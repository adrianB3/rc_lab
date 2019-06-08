//
// Created by adrianb3 on 6/8/19.
//

#ifndef HTTP_SERVER_2_REQUEST_H
#define HTTP_SERVER_2_REQUEST_H

#include <string>

class Request {
private:
    std::string req_verb;
    std::string req_file;
public:
    Request(const std::string &reqVerb, const std::string &reqFile) : req_verb(reqVerb), req_file(reqFile) {}
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
};


#endif //HTTP_SERVER_2_REQUEST_H
