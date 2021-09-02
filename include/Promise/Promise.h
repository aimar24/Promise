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

        PromiseBase(std::function<void(Handle , Handle)> p);

        private:
        void internalThen(std::any data);

        void internalCatch();

        PromiseBase& then(Handle callback);

        PromiseBase& error(CatchHandle callback);



        private:
        State _state;
        std::any _data;
        std::vector<Handle> _then;
        std::vector<CatchHandle> _catch;
        
    };


    // template<typename T>
    // class Promise{


    //     std::function<void(T)> _then;
    //     std::function<void(T)> _catch;
    //     private:
    //     T _data;

    // };

}