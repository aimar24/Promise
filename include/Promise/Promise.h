#pragma once

#include <vector>
#include <functional>
#include <any>

namespace Promise
{
    class PromiseBase
    {

        public:
        using Handle = std::function<void(std::any)>;
        using CatchHandle = std::function<void()>;
        enum State{
            Init,
            Inprogress,
            Finished,
            Failed
        };

        PromiseBase(std::function<void(Handle& , Handle&)> p);

        PromiseBase& then(Handle callback);

        PromiseBase& error(CatchHandle callback);

        private:
        void internalThen(std::any data);

        void internalCatch();

        private:
        State _state = State::Init;
        std::any _data;
        std::vector<Handle> _then;
        std::vector<CatchHandle> _catch;

        Handle _thenHandle;
        
    };


    // template<typename T>
    // class Promise{


    //     std::function<void(T)> _then;
    //     std::function<void(T)> _catch;
    //     private:
    //     T _data;

    // };

}
