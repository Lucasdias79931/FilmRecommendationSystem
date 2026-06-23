#include "worker_controller.h"


Status Worker_Controller::Save(
    ServerContext* context, const MovieRPC* request, Handle* response){
    try{
        Handle result = WorkerService::Save(*request, storage);

        response->CopyFrom(result);

        return Status::OK;
        
    }catch(const std::exception& e){
        return Status(grpc::StatusCode::INTERNAL, e.what());
    }
}



Status Worker_Controller::Delete(ServerContext* context, const GetRequest* request, Handle* response) {

    try{

        Handle result = WorkerService::Delete(request->id(), storage);

        response->CopyFrom(result);
        
        return Status::OK;
        
    }catch(const std::exception& e){
        return Status(grpc::StatusCode::INTERNAL, e.what());
    }
}

Status Worker_Controller::GetAll(ServerContext* context, const FiltersRPC* request, MoviesRPC* response) {
    return Status::OK;
}

Status Worker_Controller::Get(ServerContext* context, const GetRequest* request, MovieRPC* response) {
    return Status::OK;
}