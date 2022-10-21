//#include <iostream>
//#include <string>
//#include <vector>
//#include <utility>
//#include <initializer_list>
//using namespace std;
//
//typedef pair<string, string> Rule;
//typedef pair<Rule, bool> Element;
//typedef vector<Element> rules;
//
//class Markov
//{
//    rules markov;
//    string str;
//
//public:
//    Markov() 
//        :  markov() 
//    { }
//
//    Markov(const initializer_list<Element>& rls)
//        : markov()
//    {
//        for (const Element& r : rls)
//            markov.push_back(r);
//    }
//
//    Markov(const vector<Element>& vec)
//        : markov()
//    {
//        for (const Element& r : vec)
//            markov.push_back(r);
//    }
//
//    void set_str(const string& s)
//    {
//        str = s;
//    }
//
//    bool step()
//    {
//        size_t pos;
//        for (Element& r : markov)
//            if ((pos = str.find(r.first.first)) != string::npos)
//            {
//                str.replace(pos, r.first.first.size(), r.first.second);
//                if (r.second) return true;
//                return false;
//            }
//        return true;
//    }
//
//    string& get_current()
//    {
//        return str;
//    }
//};
//
//Element create(const string& before, const string& after, bool end = false)
//{
//    return make_pair(make_pair(before, after), end);
//}
//
//int main()
//{
//    Markov NAM =
//    {              
//                   create("|b", "ba|"),
//                   create("ab", "ba"),
//                   create("b", ""),
//                   create("*|", "b*"),
//                   create("*", "c"),
//                   create("|c", "c"),
//                   create("ac", "c|"),
//                   create("c", "", true)
//    }; 
//
//    cout << "String:  |*|| " << "\n";
//    cout << "Use of rules: \n";
//    NAM.set_str("|*||");
//    while (!NAM.step())
//    {
//        cout << NAM.get_current() << endl;
//    }
//
//    cout << "Result: " << NAM.get_current() << endl;
//
//    system("pause");
//    return 0;
//}