#ifndef IOC_H
#define IOC_H

#include <functional>

namespace ioc {

/*!
 * Dependency Provider
 */
template <typename T>
class Provider {
public:
    Provider() {}

    Provider(std::function<T*()> creator, std::function<void(T*)> destroyer) {
        this->creator = creator;
        this->destroyer = destroyer;
    }

    virtual ~Provider() {
        if (instance == nullptr) {
            return;
        }

        if (destroyer != nullptr) {
            destroyer(instance);
        } else {
            delete instance;
        }
    }

    virtual T* get() {
        if (instance == nullptr) {
            instance = createInstance();
        }
        return instance;
    }

    virtual T* createInstance() {
        return (creator != nullptr) ? creator() : new T();
    }

private:
    T* instance = nullptr;
    std::function<T*()> creator = nullptr;
    std::function<void(T*)> destroyer = nullptr;
};


} // namespace

#endif // IOC_H
