#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "worker_controller.h"   
#include "data-structures/storage.h"

void server(std::string server_address, Storage& storage){
    Worker_Controller service(storage);

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    builder.SetSyncServerOption(grpc::ServerBuilder::SyncServerOption::MAX_POLLERS,2);
    builder.SetMaxSendMessageSize(1024 * 1024 * 1024);
    builder.SetMaxReceiveMessageSize(1024 * 1024 * 1024);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server running on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char* argv[]) {

    Storage storage("../../data/db.json");
    std::string server_address = "0.0.0.0:50051";

    server(server_address, storage);

    return 0;
}
