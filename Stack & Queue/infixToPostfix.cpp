int evalRPN(vector<string>& tokens) {
        stack<int> st;

    for(auto ch: tokens){
        
        if(ch == "*" || ch == "/" || ch == "+" || ch == "-"){
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            if(ch == "+"){
                st.push(op1 + op2);
            }
            if(ch == "-"){
                st.push(op1 - op2);
            }
            if(ch == "*"){
                st.push(op1 * op2);
            }
            if(ch == "/"){
                st.push(op1 / op2);
            }
        } else {
            stringstream ss(ch);
            int data;
            ss >> data;
            st.push(data);
        }
    }
    return st.top();
    }