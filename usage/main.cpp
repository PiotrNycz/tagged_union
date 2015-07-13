#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

#include <unrestricted_union.hpp>
#include <indexed_union.hpp>
#include <tagged_union.hpp>

template <typename T>
struct print;

void use_indexed_union()
{
    exp::indexed_union<std::string,int,std::vector<int>> a, b;

    cout << a.at<0>() << endl;
    a.emplace<0>("Hello World");
    cout << a.at<0>() << endl;
    a.get<0>() = "Bye World";
    cout << a.at<0>() << endl;
    cout << a.get<2>().size() << endl;
    a.emplace<1>(13);
    cout << a.at<1>() << endl;

    cout << "--------" << endl;
    b.emplace<2>(std::initializer_list<int>({1,2,3,4}));
    cout << b.get<2>().size() << endl;
    auto c = b;
    cout << b.at<2>().size() << endl;
    auto d = std::move(b);
    cout << d.at<2>().size() << endl;
    cout << b.at<2>().size() << endl;

    decltype(d) e;
    e = d;
    cout << e.at<2>().size() << endl;

    decltype(d) f;
    f = std::move(d);
    cout << f.at<2>().size() << endl;
    cout << d.at<2>().size() << endl;
}

enum discriminator { name, number, dimensions };
void use_tagged_union()
{
    exp::tagged_union<discriminator>
            ::with<name>::as<std::string>
            ::with<number>::as<int>
            ::with<dimensions>::as<std::vector<int>>::type a, b;

    cout << a.at<name>() << endl;
    a.emplace<name>("Hello World");
    cout << a.at<name>() << endl;
    a.get<name>() = "Bye World";
    cout << a.at<name>() << endl;
    cout << a.get<dimensions>().size() << endl;
    a.emplace<number>(13);
    cout << a.at<number>() << endl;

    cout << "--------" << endl;
    b.emplace<dimensions>(std::initializer_list<int>({1,2,3,4}));
    cout << b.get<dimensions>().size() << endl;
    auto c = b;
    cout << b.at<dimensions>().size() << endl;
    auto d = std::move(b);
    cout << d.at<dimensions>().size() << endl;
    cout << b.at<dimensions>().size() << endl;

    decltype(d) e;
    e = d;
    cout << e.at<dimensions>().size() << endl;

    decltype(d) f;
    f = std::move(d);
    cout << f.at<dimensions>().size() << endl;
    cout << d.at<dimensions>().size() << endl;
}

int main()
{
    std::cout << "use_indexed_union()\n";
    use_indexed_union();
    std::cout << "use_tagged_union()\n";
    use_tagged_union();
    return 0;
}

