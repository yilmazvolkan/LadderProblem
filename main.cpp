#include <iostream>
#include <sstream>
#include <fstream>
#include "vector"
#include <iterator>
#include <list>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;
typedef pair<int, int> iPair;

struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;
    Graph(int V, int E)
    {
        this->V = V; //number of vertices
        this->E = E; //number of edges
    }
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}}); //Add an edge of u-v with weight w
    }
    void kruskal(ofstream& dumFile,vector<set<int>>* setOfQueries);
};
struct Trees
{
    int *ancestor, *indices;
    int v;
    map<int,int> *m;
    Trees(int v)
    {
        this->v = v;
        ancestor = new int[v+1];
        indices = new int[v+1];
        m = new map<int,int>();
        // Each vertex is in own subtree
        for (int i = 0; i <= v; i++)
        {
            indices[i] = 0;
            ancestor[i] = i;
        }
    }
    //Common Ancestor
    int find(int u)
    {
        if (u != ancestor[u])
            ancestor[u] = find(ancestor[u]);
        return ancestor[u];
    }
    void merge(int x, int y,vector<set<int>>* setOfQueries,ofstream& dumFile, int w)
    {
        x = find(x), y = find(y);
        if (indices[x] > indices[y]){
            ancestor[y] = x;
            for (set<int>::iterator it = (*setOfQueries)[y].begin(); it!=(*setOfQueries)[y].end(); ++it){
                set<int>::iterator it2 = (*setOfQueries)[x].find(*it);

                if(it2 == (*setOfQueries)[x].end()){
                    (*setOfQueries)[x].insert(*it);
                    //cout << "check 1" << endl;
                    //cout << *it << endl;
                }
                else{
                    //cout << "check 2" << endl;
                    //cout << *it << endl;
                    (*m)[*it] = w;
                    //dumFile << w << endl;
                }
            }
        }
        else if(indices[x] <= indices[y]){
            ancestor[x] = y;
            for (set<int>::iterator it = (*setOfQueries)[x].begin(); it!=(*setOfQueries)[x].end(); ++it){
                set<int>::iterator it2 = (*setOfQueries)[y].find(*it);
                if(it2 == (*setOfQueries)[y].end()){
                    (*setOfQueries)[y].insert(*it);
                    //cout << "check 3" << endl;
                    //cout << *it << endl;
                }
                else{
                    //cout << "check 4" << endl;
                    //cout << *it << endl;
                    (*m)[*it] = w;
                    //dumFile << w << endl;
                }

            }
        }
        //cout << "qs " << (*(*setOfQueries)[6].begin()) << endl;
        //cout << "parent " << x << " " << parent[x] << " -- "<< y << " " << parent[y] << endl;
        if (indices[x] == indices[y])
            indices[y]++;
    }
    void printer(ofstream& dumFile){
        for (map<int, int>::iterator it = m->begin(); it != m->end(); ++it ){
            dumFile << it->second << endl;
        }
    }
};

void Graph::kruskal(ofstream& dumFile,vector<set<int>>* setOfQueries)
{
    sort(edges.begin(), edges.end());
    Trees ts(V);
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
        int w = it->first;  // Last weight

        int set_u = ts.find(u);
        int set_v = ts.find(v);
        //cout << "u " << u << " v " << v << endl;

        //Check cycles
        if (set_u != set_v)
        {
            //cout << u << " - " << v << " - " << w << endl;
            //cout << (*setOfQueries)[u].size() << endl
            //cout << set_u << " - " << set_v << endl;
            ts.merge(set_u, set_v,setOfQueries,dumFile,w);
        }
    }
    ts.printer(dumFile);
}
// Taking input
template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Run the code with the following command: ./project4 [input_file] [output_file]" << endl;
        return 1;
    }
    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;
    ifstream infile(argv[1]);
    string line;
    getline(infile, line);
    vector<string> words;
    split1(line, words);

    int N = stoi(words[0]); //ROWS
    int M = stoi(words[1]); //COLUMNS

    int V = M*N;
    int E = N*(N-1) + M*(M-1);
    Graph g(V, E);

    int index = 0;
    int prevXV = 0;
    int prevVals[N];
    for (int i = 0; i < N; i++) { //x N
        getline(infile, line);
        vector<string> words;
        split1(line, words);
        for (int j = 0; j < M; j++) { //y M
            int a = stoi(words[j]); //weight
            if((i != 0 || j!=0) && j != M && j!=0) {
                g.addEdge(index-1, index,abs(prevXV-a));
                // cout << "YAN "<< "i: " << (index-1) << " i2: " << (index) << " val: " << abs(prevXV-a) << endl;
            }
            if(i != 0) {
                g.addEdge(index-M, index,abs(prevVals[j]-a));
                //cout << "ALT "<< "i: " << (index-M) << " i2: " << (index) << " val: " << abs(prevVals[j]-a) << endl;
            }
            prevVals[j] = a;
            prevXV = a;
            index++;
        }
    }

    getline(infile, line);
    vector<string> words2;
    split1(line, words2);
    int I = stoi(words2[0]); //INPUTS
    int source = 0;
    int sink = 0;
    ofstream myFile;
    myFile.open(argv[2]);
    //set<int> setOfQueries[V];
    //set<int> *setOfQueries = new set<int>[V];
    //vector <set<int>> *setOfQueries = new  vector <set<int>>(V);
    vector <set<int>> setOfQueries(V);
    for (int i = 0; i < I; i++) { //TODO I
        getline(infile, line);
        vector<string> words;
        split1(line, words);
        source = N*(stoi(words[0])-1)+stoi(words[1])-1;
        sink = N*(stoi(words[2])-1)+stoi(words[3])-1;
        //(*setOfQueries)[source].insert(i);
        //(*setOfQueries)[sink].insert(i);
        setOfQueries[source].insert(i+1);
        setOfQueries[sink].insert(i+1);
        //cout << "source " << source << " sink " << sink << endl;
    }
    g.kruskal(myFile, &setOfQueries);
    return 0;
}
