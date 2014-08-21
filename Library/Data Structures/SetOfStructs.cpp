struct sol{
    int a,b,pp1,pp2,pr;
    bool operator<(const sol& rhs) const{
        return a < rhs.a;
    }
    bool operator==(const sol& rhs) const{
        return a==rhs.a&&b==rhs.b&&pp1==rhs.pp1&&pp2==rhs.pp2&&pr==rhs.pr;
    }
};
set<sol> s;
