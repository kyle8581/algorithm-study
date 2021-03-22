#include <iostream>
#include <vector>
using namespace std;
bool paper_check(vector<vector<int> > paper){
    int initial_e = paper[0][0];
    for(int i=0;i<paper.size(); i++ ){
        for(int j=0;j<paper.size();j++){
            if (paper[i][j] != initial_e){
                // cout<< "paper check false"<<endl;
                return false;
            }
        }
    }
    // cout<< "paper check true"<<endl;

    return true;
}
vector <int> add_vector(vector <int> v1, vector <int> v2){
    for(int i=0;i<3;i++){
        v1[i] += v2[i];
    }
    return v1;
}

vector <int> identify_paper(vector <vector<int> > paper){
    vector<int> counter(3);
    if(paper[0][0] == -1) counter[0] += 1;
    else if(paper[0][0] == 0 ) counter[1] += 1;
    else counter[2] += 1;
    return counter;

}
vector<vector<vector<int> > > divide_paper(vector<vector<int> > paper, int divided_size){
    vector<vector<vector<int> > > paper_vector;
    // int divided_size = paper.size()/3;
        for(int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                vector<vector<int> > divided_paper;
                for(int k=0;k<divided_size;k++){
                    vector<int>tmp = vector<int> (paper[i*divided_size + k].begin()+divided_size*j, paper[i*divided_size + k].begin()+divided_size*(j+1));
                    divided_paper.push_back(tmp);

                }
                paper_vector.push_back(divided_paper);
            }
        }
    return paper_vector;
}
void print_paper(vector< vector<int> > paper){
    cout << "--------";
    cout << endl;
     for(int i=0;i<paper.size();i++){
            for (int j=0;j<paper[0].size();j++){
                cout << paper[i][j] << " ";
            }
            cout << endl;    
        }
    cout << "--------";
    cout << endl;
}
vector <int> paper_cut(vector<vector<int> > paper){
    
    // print_paper(paper);
    if(paper.size() == 1){
        return identify_paper(paper);
    }
    else{
        if(paper_check(paper)){
            return identify_paper(paper);
        }
        else{
            vector<int> counter(3);
            int divided_size = paper.size()/3;
            vector<vector<vector<int> > > divided_paper=divide_paper(paper, divided_size);
            for(int i=0;i<9;i++){
                counter = add_vector(counter, paper_cut(divided_paper[i]));
            }
            return counter;


        }
    }

}
int main(){
    int n;
    cin >> n;
    vector <vector<int> > paper;
    for(int i=0;i<n;i++){
        vector<int> p;
        paper.push_back(p);

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            paper[i].push_back(x);
        }

    }
    vector<int> answer = paper_cut(paper);
    for(int i=0; i<3;i++){
        cout << answer[i] << endl;
    }




}