#pragma once
#include "../grpc_common.h"
#include <memory>

class Master {
private:
    std::unique_ptr<database_service::DatabaseService::Stub> stub_;

public:
    explicit Master(std::shared_ptr<grpc::Channel> channel);

    database_service::Handle Save(const database_service::MovieRPC& movie);

    database_service::Handle Delete(std::string& id);
};