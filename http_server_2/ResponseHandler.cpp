#include <fstream>
#include <algorithm>
#include "ResponseHandler.h"

const std::string badreq = "400 Bad Request";
const std::string success = "200 OK";
const std::string serverror = "500 Internal Server Error";
const std::string notfound = "404 Not Found";

std::string ResponseHandler::getResponse(Request req){
    std::string header = "";
    std::string body = "";

    std::string verb = req.getReqVerb();
    std::string file = req.getReqFile();
    std::string proto = req.getReqProto();


    if(verb.empty() || file.empty() || proto.empty()){
        body += "Bad request";
        header += "HTTP/1.1 " + badreq + "\n";
        header += "Content-Type: text/plain; charset=utf-8\n";
        header += "Content-Length: " + std::to_string(body.length()) + "\n";
    }
    else{

        if(file.compare("/") == 0){
            file = "/index.html";
        }

        file.erase(0, 1); // delete the "/"

        std::ifstream filestream;
        filestream.open("../public/" + file, std::ios::binary);

        if (!filestream.is_open()){
            body += "Not Found";
            header += proto + " " + notfound + "\n";
            header += "Content-Type: text/plain; charset=utf-8\n";
            header += "Content-Length: " + std::to_string(body.length()) + "\n";
        }
        else{

            if(req.getReqAccType().find("image") != std::string::npos){

               // body = std::string(filestream.rdbuf());
                body.assign( (std::istreambuf_iterator<char>(filestream) ),
                                     (std::istreambuf_iterator<char>()) );

                header += proto + " " + success + "\n";
                header += "Content-Type: " + req.getReqAccType() + "\n";
                header += "Content-Length: " + std::to_string(body.length()) + "\n";
            }
            else {
                std::string line;
                while ( getline (filestream,line) )
                {
                    body += line;
                }
                header += proto + " " + success + "\n";
                if(req.getReqFile().find("js") != std::string::npos){
                    header += "Content-Type: text/javascript; charset=utf-8\n";
                }
                else {
                    header += "Content-Type: text/html; charset=utf-8\n";
                }
                header += "Content-Length: " + std::to_string(body.length()) + "\n";
            }
            filestream.close();
        }
    }


    return header + "\r\n" + body;
}