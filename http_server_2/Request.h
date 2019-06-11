#ifndef HTTP_SERVER_2_REQUEST_H
#define HTTP_SERVER_2_REQUEST_H

#include <string>

class Request {
private:
    std::string req_verb;
    std::string req_file;
    std::string req_proto;
public:
    Request(const std::string &reqVerb, const std::string &reqFile, const std::string &reqProto) : req_verb(reqVerb),
                                                                                                   req_file(reqFile),
                                                                                                   req_proto(reqProto) {}

    Request() {}

    const std::string &getReqVerb() const {
        return req_verb;
    }

    void setReqVerb(const std::string &reqVerb) {
        req_verb = reqVerb;
    }

    const std::string &getReqFile() const {
        return req_file;
    }

    void setReqFile(const std::string &reqFile) {
        req_file = reqFile;
    }

    const std::string &getReqProto() const {
        return req_proto;
    }

    void setReqProto(const std::string &reqProto) {
        req_proto = reqProto;
    }
};


#endif //HTTP_SERVER_2_REQUEST_H
