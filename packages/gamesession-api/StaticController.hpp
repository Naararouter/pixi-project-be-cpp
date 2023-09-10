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

    ENDPOINT("GET", "ws", ws, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
        return oatpp::websocket::Handshaker::serversideHandshake(request->getHeaders(), websocketConnectionHandler);
    };

    ENDPOINT("GET", "health", healthCheck) {
        return createResponse(Status::CODE_200, "OK");
    }
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif //CRUD_STATICCONTROLLER_HPP