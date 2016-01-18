#ifndef IOTPOS_USER_H
#define IOTPOS_USER_H


class User {
public:
    User();
    virtual ~User();
};

class Salesman : public User {
public:
    Salesman();
    virtual ~Salesman();
};

class Customer : public User {
public:
    Customer();
    virtual ~Customer();
};


#endif //IOTPOS_USER_H
