#ifndef LEMON_USER_H
#define LEMON_USER_H


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


#endif //LEMON_USER_H
