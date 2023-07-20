#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'getTravelCosts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER source
 *  2. INTEGER target
 *  3. WEIGHTED_INTEGER_GRAPH g
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */
 const int N= 1e5+5;
 int n;
 
vector<int> dist_src(N);
vector<int> dist_dest(N);
vector<int> vis_1(N);
vector<int> vis_2(N);

vector<vector<pair<int,int>>> adj_src(N);
vector<vector<pair<int,int>>> adj_dest(N);

class prioritize{
 public : bool operator()(pair<int,int> &p1, pair<int, int> &p2){
    return p1.second> p2.second;
 }
};

 
void dijkstra1(int src){

    for(int i=1; i<=n; i++){
        dist_src[i]= 1e8;
        vis_1[i]=0;
    }

    dist_src[src]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, prioritize> pq;

    pq.push(make_pair(src,0));

    while(!pq.empty()){
        pair<int,int> fs= pq.top(); 
        pq.pop();

        if(vis_1[fs.first]) continue;

        vis_1[fs.first]=1; //mark the topmost element

        for(auto v: adj_src[fs.first]){
            //relax the neighbours
            int neigh= v.first;
            int wt= v.second;

            if(dist_src[neigh]> dist_src[fs.first]+ wt){
                dist_dest[neigh]= dist_dest[fs.first]+ wt;
                pq.push(make_pair(neigh,dist_src[neigh]));
            }
        }

    }

}


void dijkstra2(int src){

    for(int i=1; i<=n; i++){{
        dist_dest[i]= 1e8;
        vis_2[i]=0;
    }

    dist_dest[src]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, prioritize> pq;

    pq.push(make_pair(src,0));

    while(!pq.empty()){
        pair<int,int> fs= pq.top(); 
        pq.pop();

        if(vis_2[fs.first]) continue;

        vis_2[fs.first]=1; //mark the topmost element

        for(auto v: adj_dest[fs.first]){
            //relax the neighbours
            int neigh= v.first;
            int wt= v.second;

            if(dist_dest[neigh]> dist_dest[fs.first]+ wt){
                dist_dest[neigh]= dist_dest[fs.first]+ wt;
                pq.push(make_pair(neigh,dist_dest[neigh]));
            }
        }

    }

}
}

vector<int> getTravelCosts(int source, int target, int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight){
   n= g_nodes;
  
   vis_1.resize(n+1,0);
   vis_2.resize(n+1, 0);
   
   int edges= g_from.size();
   
   adj_src.clear();
   adj_src.resize(n+1);
   
   adj_dest.clear();
   adj_dest.resize(n+1);
   
   for(int i=0; i<edges; i++){
       adj_src[g_from[i]].push_back({g_to[i],g_weight[i]});
       adj_dest[g_to[i]].push_back({g_from[i],g_weight[i]});
   }
   
   dijkstra1(source);
   dijkstra2(target);
   
   for(auto x: dist_src) cout<<x<<" ";
   cout<<endl;
   for(auto x: dist_dest) cout<<x<<" ";
   cout<<endl;
   
   
// //    vector<int> ans(edges);
// //    for(int i=0; i<edges; i++){
// //        int u= g_from[i]; int v= g_to[i];
       
//     }
    
    vector<int> fff;

return fff;
  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string source_temp;
    getline(cin, source_temp);

    int source = stoi(ltrim(rtrim(source_temp)));

    string target_temp;
    getline(cin, target_temp);

    int target = stoi(ltrim(rtrim(target_temp)));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    vector<int> result = getTravelCosts(source, target, g_nodes, g_from, g_to, g_weight);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
