#include <iostream>

class B1 {
	public:

    virtual void vf() {
        std::cout<<"B1::vf()\n";
    }

    void f() {
        std::cout<<"B1::f()\n";
    }

    virtual void pvf() = 0;
};

class D1 : public B1 {
    public:

    virtual void vf() override {
        std::cout<<"D1::vf()\n";
    }

    void f() { //enelkűl a B1-ből hívodna meg az f function
        std::cout<<"D1::f()\n";
    }

    void pvf() override {
        std::cout<<"D1::pvf()\n";
    }

};

class D2 : public D1 {
    public:

    void pvf() override {
        std::cout<<"D2::pvf()\n";
    }
};

class B2 {
    public:
    virtual void pvf() = 0;
};

class D21 : public B2 {
    public:
    void pvf() override {
        std::cout<<astring;
    }

    private:
    std::string astring = "Béreslegény mezítláb ment szántani\n";
};

class D22 : public B2 {
    public:
    void pvf() override {
        std::cout<<n<<std::endl;
    }

    private:
    int n=10;
};

void f(B2 &bazis) {
    bazis.pvf();
} 


int main()
{
    /*
    B1 b;
    b.vf();
    b.f();
    */
    
    D1 d;
    d.vf();
    d.f();

    B1 &b_ref = d;
    b_ref.f();
    b_ref.vf();
    b_ref.pvf();
    
    D2 dd;
    dd.pvf();
    dd.vf();
    dd.f();

    D21 dbb;
    D22 ddbb;

    f(dbb);
    f(ddbb);
}