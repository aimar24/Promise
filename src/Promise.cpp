#include <Promise/Promise.h>

namespace Promise
{
        PromiseBase::PromiseBase(std::function<void(Handle& , Handle&)> p) : _state(State::Init), _thenHandle([this](std::any data){
            internalThen(data);
        }){
            //p(_then,_catch);

            //_then.push_back(thenHandle);
            p(_thenHandle
            ,_thenHandle);
        }

        void PromiseBase::internalThen(std::any data){
            _data = data;
            _state = PromiseBase::State::Finished;

            for(const auto& callback: _then)
            {
                (callback)(_data);
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

            if(State::Finished == _state)
            {
                callback(_data);
            }

            return *this;
        }

        PromiseBase& PromiseBase::error(CatchHandle callback){
            _catch.push_back(callback);

            if(State::Failed == _state)
            {
                callback();
            }

            return *this;
        }
}
