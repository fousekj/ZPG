#pragma once

template<class T>
class Observer {
public:
    virtual void update(T* subject) {

    }

    virtual void update(T* subject, int descriptor) {

    }
};