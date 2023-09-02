#ifndef WSMessage_hpp
#define WSMessage_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class WSMessageDto : public oatpp::DTO {

    DTO_INIT(WSMessageDto, DTO)

    DTO_FIELD(String, message, "message");

};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
