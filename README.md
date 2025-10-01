# adapter-mod

This test C++ "solution" for Visual Studio 2026 (open the file `adapter-mod.slnx`) explores
what happens, if two libraries have a module with the same name (`X`).

The main project builds a Windows exe, which returns a value (file `main/main.cpp`):

    import XA;
    import XB;

    int main() {
        auto z1 = XA::Z{};
        auto z2 = XB::Z{};
        z1.add();
        z2.add();
        auto sum = z1.i + z2.i;
        return sum;
    }

It imports two modules: XA and XB.

Module `XA` is defined in library XA (file `XA/XA.ixx`):

    export module XA;

    import X;  // from library A

    export namespace XA
    {

    using Z = X::Z;

    }

`XA` imports module `X`, which is defined in library `A` (file `A/X.ixx`):

    export module X;  // library A

    namespace X
    {

    export struct Z
    {
        int i = 42;
        void add()
        {
            i = i + 7;
        }
    };

    }


Module `XB` is defined in library `XB` (file `XB/XB.ixx`):

    export module XB;

    import X;  // from library B

    export namespace XB
    {

    using Z = X::Z;

    }

`XB` imports module `X`, which is defined in library `B` (file `B/X.ixx`):

    export module X;  // library B

    namespace X
    {

    export struct Z
    {
        int i = 3;
        void add()
        {
            i = i + 17;
        }
    };

    }

So, **both libraries A and B have a module with the same name X**, but the contents
are not the same. They both have a struct Z, but the definitions differ.


<img src="/assets/solution-screenshot.png" alt="Solution screenshot" width="300"/>
