#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::string;

struct Graph
{
    private:
    string vertex;
    vector<string> edges;

    /**
     * @note this function use getEdgesOfVertex and getRowOfEdges
     * @note doesn't need parameters
     * @note it only needs that the vertices and edges are loaded correctly
     * @return vector<vector<int>>  for assign to matrix
    */
    vector<vector<int>> makeMatrix();

    /**
     * @param[in] char with this the comparison will be made
     * @param[in] bool to choose if you want to get inputs (0) or outputs (1)
     * @return vector<string> that contains the edges, according to the previous parameters
    */
    vector<string> getEdgesOfVertex(char, bool);

    /**
     * @param[in] vector<string> normally this parameter is provided by the function getEdgesOfVertex
     * @param[in] bool to choose if you want to get inputs (0) or outputs (1)
     * @return vector<int> that contains 0 or 1, according to the previous parameters
    */
    vector<int> getRowOfEdges(vector<string>, bool);

    /**
     * @note this function doesn't use parameters
     * @return vector<int> that contains degrees, automatically determines if the graph is directed or not
    */
    vector<int> getDegrees();

    vector<vector<int>> getPositions();

    string findNextVertex(int, vector<int>);

    /**
     * @return bool that determine if the graph is related
    */
    bool isRelated();

    /**
     * @return bool that determine if the graph is symmetrical
    */
    bool isSymmetrical();

    /**
     * @return bool that determine if the graph is Eulerian
    */
    bool isEulerian();
    //bool isHamilton();

    /// @brief 
    /// @param vector<int> es un vector que obtien
    /// @param  
    /// @return 
    vector<string> makeRoadAndCircuitEuler(vector<int>, int);

    bool existRoad(vector<string>);
    bool existCircuit(vector<string>, char);

    public:
    void setValuesToGraph(string, vector<string>);
    void showGraph();
    void showConvex();
    void showMatrix();
    void showIsSymmetrical();
    void showDegrees();
    void showIsEulerian();
    void runTest();
};

int main() 
{
    string txt = "\n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
    string vertex;
    vector<string> edges;


    cout << "\ngraph 1\n\n";
    vertex = "abcd";
    edges = {
        "ab","ac","ad","ba","bc","ca","cb","cd","da","dc" 
    };
    Graph graph1;
    graph1.setValuesToGraph(vertex, edges);
    graph1.runTest();
    edges.clear();
    vertex.clear();

    
    cout << txt << "\n\ngraph 2\n";
    vertex = "abcde";
    edges = {
        "ab","ac","ad","ae","ba","be","ca","cd","da","dc","ea","eb"
    };
    Graph graph2;
    graph2.setValuesToGraph(vertex, edges);
    graph2.runTest();
    edges.clear();
    vertex.clear();
    /*

    cout << txt << "\n\ngraph 3\n";
    vertex = "abcdefgh";
    edges = {
        "ab", "ac", "ag", "ba", "bd", "bh", "ca", "cd", "ce", "db", "dc", "df", "ec", "ef", "eg", "fd", "fe", "fh", "ga", "ge", "gh", "hb", "hf", "hg" 
    };
    Graph graph3;
    graph3.setValuesToGraph(vertex, edges);
    graph3.runTest();


    cout << txt << "\n\ngraph 4\n\n";
    vertex = "abcde";
    edges = {
        "ac","bc","ca","cb","cd","ce","dc","ec"
    };
    Graph graph4;
    graph4.setValuesToGraph(vertex, edges);
    graph4.runTest();
    edges.clear();
    vertex.clear();

    cout << txt << "\n\ngraph 5\n";
    vertex = "abcde";
    edges = {
        "ac", "ad", "ba", "be", "cb", "cd", "da", "de", "eb", "ec" 
    };
    Graph graph5;
    graph5.setValuesToGraph(vertex, edges);
    graph5.runTest();
    edges.clear();
    vertex.clear();

    cout << txt << "\n\ngraph 6\n";
    vertex = "abcdef";
    edges = {
        "ac", "ae", "bc", "bd", "ca", "cb", "ce", "cf", "db", "df", "ea", "ec", "fc", "fd"
    };
    Graph graph6;
    graph6.setValuesToGraph(vertex, edges);
    graph6.runTest();
    edges.clear();
    vertex.clear();
    
    cout << txt << "\n\ngraph 7\n";
    vertex = "abcdefg";
    edges = {
        "ab", "ac", "ba", "bc", "bd", "be", "ca", "cb", "cd", "cf", "db", "dc", "de", "df", "eb", "ed", "ef", "eg", "fc", "fd", "fe", "fg", "ge", "gf"
    };
    Graph graph7;
    graph7.setValuesToGraph(vertex, edges);
    graph7.runTest();
    edges.clear();
    vertex.clear();


    cout << txt << "\n\ngraph 8\n";
    vertex = "abcdef";
    edges = {
        "ab", "ae", "ba", "bc", "bd", "bf", "cb", "ce", "db", "de", "ea", "ec", "ed", "ef", "fb", "fe"
    };
    Graph graph8;
    graph8.setValuesToGraph(vertex, edges);
    graph8.runTest();
    edges.clear();
    vertex.clear();*/

    return 0;
}

void Graph::setValuesToGraph(string _vertex, vector<string> _edges) 
{
    vertex = _vertex;
    edges = _edges;
}

void Graph::showGraph() 
{
    cout << "vertex to graph: " << vertex << "\n";
    for (auto edge : edges)
        cout << edge << "\n";
}

void Graph::showConvex() 
{
    if (isRelated()) cout << "\nis convex";
    else cout << "\nisn't ";
}

void Graph::showMatrix() 
{
    vector<vector<int>> matrix = makeMatrix();
    for (auto arrow : matrix)
    {
        for (auto col : arrow)
        {
            cout << " " << col << " ";
        }
        cout << "\n";
    }
}

void Graph::showIsSymmetrical()
{
    if (isSymmetrical()) cout << "\nis Symmetrical";
    else cout << "\nnot is Symmetrical";
}

void Graph::showDegrees()
{
    vector<int> degrees = getDegrees();
    cout << "\n";
    for (int i=0; i < degrees.size(); i++ )
    {
        cout << "vertex: " << vertex.at(i) << "\t" << degrees.at(i) << "\n";
    }
}

void Graph::showIsEulerian()
{
    if (isEulerian()) cout << "\nthe graph is eulerian";
    else cout << "\nthe graph doesn't eulerian";
}

void Graph::runTest()
{
    showMatrix();
}

vector<string> Graph::getEdgesOfVertex(char v, bool inOrOut)
{
    vector<string> _edges;

    for (auto edge : edges)
    {
        if (v == edge[inOrOut])
        {
            _edges.push_back(edge);
        }
    }

    return _edges;
}

vector<int> Graph::getRowOfEdges(vector<string> _edges, bool inOrOut)
{
    vector<int> row;

    for (auto v : vertex)
    {
        bool aux = 0;
        cout << "\tv: " << v;
        for (int i=0; i < _edges.size(); i++)
        {
            cout << "\tedge: " << _edges.at(i);
            if (v == _edges.at(i)[inOrOut])
            {
                aux = 1;
                _edges.erase(_edges.begin() + i);
                break;
            }
        }
        cout << "\t" << aux << "\n";
        row.push_back(aux);
    }

    return row;
}

vector<vector<int>> Graph::makeMatrix() 
{
    vector<vector<int>> matrix;
   
    for (auto v : vertex)
    {
        cout << "\tvertex: " << v;
        matrix.push_back(getRowOfEdges(getEdgesOfVertex(v, 0), 1));
        cout << "\n";
    }

    return matrix;
}

vector<int> Graph::getDegrees()
{
    vector<int> degrees;
    vector<vector<int>> matrix = makeMatrix();

    if (isSymmetrical()) {
        for (auto col : matrix)
        {
            int i = 0;
            for (auto row : col)
            {
                if (row == 1) i++;
            }
            degrees.push_back(i);
        }

        return degrees;
    }
    else
    {
        for (auto v : vertex)
        {
            vector<int> _edges;
            int in = 0;
            int out = 0;
            _edges = getRowOfEdges(getEdgesOfVertex(v, 0), 1);
            for (auto _edge : _edges)
                if (_edge == 1) in++;
            _edges.clear();
            _edges = getRowOfEdges(getEdgesOfVertex(v, 1), 0);
            for (auto _edge : _edges)
                if (_edge == 1) out++;
            
            degrees.push_back(in + out);
        }

        return degrees;
    }
}

vector<vector<int>> Graph::getPositions()
{
    vector<vector<int>> matrix = makeMatrix();
    vector<int> aux;
    vector<vector<int>> pos;

    for (int i=0; i < matrix.size(); i++)
    {
        for (int j=0; j < matrix.at(i).size(); j++)
        {
            if (matrix.at(i).at(j) == 1)
            {
                aux.push_back(j);
            }
        }
        pos.push_back(aux);
    }

    return pos;
}

bool Graph::isRelated() 
{
    int flag = vertex.length();
    //cout << "\nflag: " << flag;
    for (auto v : vertex)
    {
        if (flag == 0) break;
        for (auto edge : edges)
        {
            //cout << "\nvertex: " << v << "\tedge: " << edge;
            if (v == edge[0] || v == edge[1])
            {
                flag --;
                break;
            }
        }
    }

    //cout << "\n\tflag: " << flag;

    if (flag == 0) return true;
    else return false;
}

bool Graph::isSymmetrical()
{
    vector<vector<int>> matrix = makeMatrix();

    for (int i=0; i < matrix.size() - 1; i++)
    {
        for (int j=1; j < matrix.size(); j++)
        {
            //cout << "\ni: " << i << "\tj: " << j;
            if (i >= j) continue;
            if (matrix[i][j] != matrix[j][i]) return false;
            //cout << "\tmatrix I [" << i << "][" << j << "]: " << matrix[i][j] << "\t=\t" << "matrix J [" << j << "][" << i << "]: " << matrix[j][i];
        }
    }

    return true;
}

bool Graph::isEulerian()
{
    if (!isRelated()) return false;
    
    vector<int> degrees = getDegrees();

    int odd = 0, degreesTotal = 0;
    vector<int> posOdd;

    for (int i=0; i < vertex.size(); i++)
    {
        if (degrees.at(i) % 2) {
            odd++;
            posOdd.push_back(i);
        }
        degreesTotal += degrees.at(i);
    }
    cout << "\namount odd: " << odd << "\n\n";
    
    if (odd == 1 || odd > 2) return false;
    
    if (odd == 0) {
        makeRoadAndCircuitEuler(posOdd, degreesTotal);
        return true;
    }

    if (odd == 2) {
        cout << "\nthe vertex odd are: " << vertex.at(posOdd.at(0)) << " " << vertex.at(posOdd.at(1)) << "\n";
        makeRoadAndCircuitEuler(posOdd, degreesTotal);
        return true;
    }
}

bool Graph::existCircuit(vector<string> circuit, char v)
{
    return (v == circuit.at(0)[0] && v == circuit.at(circuit.size())[1]);
}

bool Graph::existRoad(vector<string> road)
{
    int flag = road.size();
    for (auto r : road)
    {
        if (flag == 0) break;
        for (int i = 0; i < edges.size(); i++)
        {
            if (r == edges.at(i))
            {
                flag--;
                edges.erase(edges.cbegin() + i);
                break;
            }
        }
    }

    return (flag == 0);
}

int posNext (vector<int> rows) {
    if (rows.size() > 0) {
        for (int i=0; i < rows.size(); i++) {
            return rows.at(i);
        }
    }
    else return 0;
}

vector<vector<int>> deletePositions(int before, int now, vector<vector<int>> position)
{
    if (position.at(before).size() > 1 )
    {
        position.at(before).erase(position.at(before).begin() + now - 1);
        cout << "\nposition: [" << before << "," << now << "] deleted\n";
    }
    else
    {
        position.at(before).push_back(-1);
        position.at(before).erase(position.at(before).begin());
        cout << "\nposition: [" << before << "," << now << "] deleted\n";
    }

    if (position.at(now).size() > 1)
    {
        position.at(now).erase(position.at(now).begin() + before - 1);
        cout << "position: [" << now << "," << before << "] deleted\n\n";
    }
    else
    {
        position.at(now).push_back(-1);
        position.at(now).erase(position.at(now).begin());
        cout << "position: [" << now << "," << before << "] deleted\n\n";
    }

    return position;
}

/*vector<string> Graph::makeRoadAndCircuitEuler(vector<int >posOdd, int sizeRoad)
{
    vector<string> road;
    vector<int> positions = getPositions();

    cout << "\n";
    for (int i=0; i < vertex.length(); i++)
        for (auto position : positions)
            cout << vertex.at(i) << vertex.at(position) << "\n";

    cout << "\n\n";
    for (auto edge : edges)
        cout << edge << "\n";

    return road;
}*/

vector<string> Graph::makeRoadAndCircuitEuler(vector<int> posOdd, int sizeRoad)                   
{
    vector<string> road;
    vector<vector<int>> position = getPositions();

    if (isSymmetrical()) 
    {
        if (posOdd.size() == 2)
        {
            cout << "\n";
            for (auto rows : position)
            {
                for (auto cols : rows)
                {
                    cout << cols << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            
            sizeRoad = sizeRoad / 2;

            string edge;
            int posBegin = posOdd.at(0), posEnd = posOdd.at(1);
            int posBef, posNow;

            posBef = posBegin;
            posNow = posNext(position.at(posBef));
            cout << "\nbefore: " << posBef << "\tnow: " << posNow << "\t\t";
            position = deletePositions(posBef, posNow, position);
            edge = {
                vertex.at(posBef), vertex.at(posNow)
            };
            road.push_back(edge);
            cout << "edge: " << road.at(0);
            edge.clear();

            posBef = posNow;
            posNow = posNext(position.at(posBef));
            cout << "\nbefore: " << posBef << "\tnow: " << posNow << "\t\t";
            position = deletePositions(posBef, posNow, position);
            edge = {
                vertex.at(posBef), vertex.at(posNow)
            };
            road.push_back(edge);
            cout << "edge: " << road.at(0);
            edge.clear();

            posBef = posNow;
            posNow = posNext(position.at(posBef));
            cout << "\nbefore: " << posBef << "\tnow: " << posNow << "\t\t";
            position = deletePositions(posBef, posNow, position);
            edge = {
                vertex.at(posBef), vertex.at(posNow)
            };
            road.push_back(edge);
            cout << "edge: " << road.at(0);
            edge.clear();

            cout << "\n";
            for (auto r : road)
            {
                cout << r << "\t";
            }
            cout << "\n";

            
        }
        else
        {
            
        }
    }
    else {

    }

    return road;
}