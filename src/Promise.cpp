#include <Promise/Promise.h>

namespace Promise
{
        PromiseBase::PromiseBase(std::function<void(Handle , Handle)> p) : _state(State::Init){
            //p(_then,_catch);
            p([this](std::any data){
                internalThen(data);   
            }
            ,[this](std::any data){
                internalCatch();   
            });
        }

        void PromiseBase::internalThen(std::any data){
            _data = data;
            _state = PromiseBase::State::Finished;

            for(const auto& callback: _then)
            {
                callback(_data);
            }
            
        }

        void PromiseBase::internalCatch(){
            _state = PromiseBase::State::Failed;
            for(const auto& callback: _catch)
            {
                callback();
            }
            
        }

        PromiseBase& PromiseBase::then(Handle callback){
            _then.push_back(callback);

            return *this;
        }

        PromiseBase& PromiseBase::error(CatchHandle callback){
            _catch.push_back(callback);
            return *this;
        }
}