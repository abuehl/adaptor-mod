# adapter-mod

This C++ "solution" for Visual Studio 2026 (open the file adapter-mod.slnx) tests
what happens, if two libraries have a module with the same name.

The main project builds a Windows exe, which returns a vlaue (file main/main.cpp):

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

<img src="/assets/solution-screenshot.png" alt="Solution screenshot" width="300"/>
