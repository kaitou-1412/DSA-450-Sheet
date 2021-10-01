void dfs(Node* node, Node* copy, vector<Node*> &visited)
    {
        visited[copy->val] = copy;
        for(auto x: node->neighbors)
        {
            if(visited[x->val] == NULL)
            {
                Node* newNode = new Node(x->val);
                (copy->neighbors).push_back(newNode);
                dfs(x, newNode, visited);
            }
            else
            {
                (copy->neighbors).push_back(visited[x->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) 
    {
        if(node == NULL) return NULL;
        vector<Node*> visited(1000, NULL);
        Node* copy = new Node(node->val);
        dfs(node, copy, visited);
        return copy;
    }