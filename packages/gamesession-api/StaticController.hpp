#ifndef CRUD_STATICCONTROLLER_HPP
#define CRUD_STATICCONTROLLER_HPP

#include <fstream>
#include <sstream>
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp-websocket/Handshaker.hpp"
#include "oatpp/network/ConnectionHandler.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

#include <filesystem>
#include <iostream>
#include <cmath>
#include <chrono>
#include <future>

#include <array>
#include <cstdint>
#include <random>

std::string getMimeType(const std::filesystem::path& path) {
    const std::unordered_map<std::string, std::string> mimeTypes = {
            {".html", "text/html"},
            {".css", "text/css"},
            {".js", "application/javascript"},
            {".json", "application/json"},
            {".png", "image/png"},
            {".jpg", "image/jpeg"},
            {".jpeg", "image/jpeg"},
            {".gif", "image/gif"},
            {".svg", "image/svg+xml"},
            {".ico", "image/x-icon"},
            {".txt", "text/plain"},
            {".pdf", "application/pdf"}
    };

    auto ext = path.extension().string();
    auto it = mimeTypes.find(ext);

    if (it != mimeTypes.end()) {
        return it->second;
    }

    return "application/octet-stream";
}



class StaticController : public oatpp::web::server::api::ApiController {
private:
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, websocketConnectionHandler, "websocket");
public:
    StaticController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
public:

    static std::shared_ptr<StaticController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<StaticController>(objectMapper);
    }

    auto createStaticResponse(const std::filesystem::path& path) {
        //std::filesystem::path currentWorkingDirectory = std::filesystem::current_path();
        std::ifstream fileStream(path, std::ios::in | std::ios::binary);
        if (fileStream) {
            std::ostringstream ss;
            ss << fileStream.rdbuf();
            fileStream.close();
            auto mime = getMimeType(path);
            if (mime.starts_with("image/")) { 
                auto response = createResponse(Status::CODE_200, ss.str());
                response->putHeader(Header::CONTENT_TYPE, mime.c_str());
                return response;
            }
            std::cout << mime << std::endl;
            auto response = createResponse(Status::CODE_200, ss.str().c_str());
            response->putHeader(Header::CONTENT_TYPE, mime);
            return response;
        }
        return createResponse(Status::CODE_404, "File not found");
    }

    ENDPOINT("GET", "ws", ws, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
        return oatpp::websocket::Handshaker::serversideHandshake(request->getHeaders(), websocketConnectionHandler);
    };

    ENDPOINT("GET", "*", files, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
        //return createResponse(Status::CODE_511, "Not Found2");
        //return createResponse(Status::CODE_404, "Not Found131234");
        auto path = request->getPathTail().getValue("");
        if (path == "") path = "index.html";
        std::filesystem::path baseDir("public");
        std::cout << "filePath: " << path << std::endl;
        std::filesystem::path fullPath = baseDir / path;

        std::cout << "Requested path: " << fullPath << std::endl;
        std::cout << "Current directory: " << std::filesystem::current_path() << std::endl;

        // Check if the path points to a file
        if (std::filesystem::exists(fullPath) && std::filesystem::is_regular_file(fullPath)) {
            return createStaticResponse(fullPath);
        }

        return createResponse(Status::CODE_404, "Not Found1");
    }

    ENDPOINT("GET", "/sleep", sleepRandom) {
        // Generate random sleep time between 100ms and 300ms
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1000, 1500);
        int sleep_time = dist(gen);

        // Sleep for the generated time
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

        // Return the sleep time in the response
        return createResponse(Status::CODE_200, "Slept for " + std::to_string(sleep_time) + " ms");
    }


//    ENDPOINT("GET", "/load", loadTesting) {
//        auto start_time = std::chrono::high_resolution_clock::now();
//
//        auto pure = std::pow(10, 5);
//        auto max = static_cast<int>(pure);
//
//        for (auto i = 0; i < max; i++) {
//            // long calculation
//        }
//
//        auto end_time = std::chrono::high_resolution_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
//
//        std::ostringstream duration_str_stream;
//        duration_str_stream << duration;
//        std::string duration_str = duration_str_stream.str();
//
//        std::cout << "Execution Time: " << duration << " ms" << std::endl;
//
//        return createResponse(Status::CODE_200, duration_str + "ms");
//    }

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif //CRUD_STATICCONTROLLER_HPP