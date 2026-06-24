#include "grpc_master.h"


Master::Master(std::shared_ptr<grpc::Channel> channel) : stub_(DatabaseService::NewStub(channel)) {}

Handle Master::Save(const MovieRPC& movie) {
    ClientContext context;
    Handle response;

    Status status = stub_->Save(&context, movie, &response);

    if (!status.ok()) {
        throw std::runtime_error(status.error_message());
    }

    return response;
}

Handle Master::Delete(std::string& id) {
    ClientContext context;
    Handle response;

    GetRequest request;
    request.set_id(id);

    Status status = stub_->Delete(&context, request, &response);

    if (!status.ok()) {
        throw std::runtime_error(status.error_message());
    }

    return response;
}

MoviesRPC Master::GetAll(FiltersRPC& filters){
    ClientContext context;
    MoviesRPC movies;

    Status status = stub_->GetAll(&context, filters, &movies);

    if (!status.ok()) {
        throw std::runtime_error(status.error_message());
    }

    return movies;
}


