#ifndef SINGLETON_HPP
#define SINGLETON_HPP

template <class T>
class Singleton
{
public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    static T &instance()
    {
        static T singleton;
        return singleton;
    }

    bool isSingleton() const { return this == &instance(); }

protected:
    Singleton(){};
};

#endif