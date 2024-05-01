class Solution {
public:
    long long solve(int i, vector<vector<int>>& questions, vector<long long>& t) {
        if( i >= questions.size())return 0;
        if(t[i]!=-1)
        {
            return t[i];
        }
 
        long long taken = questions[i][0] + solve(i+questions[i][1]+1,questions,t);
        long long not_taken= solve(i+1,questions,t);

        return t[i]= max(taken,not_taken);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> t (questions.size()+1,-1);
        return solve( 0, questions,t);
    }
};