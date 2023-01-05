#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

vector<int> get_ring(vector<vector<int>> matrix, int r)
{
  vector<int> result;

  int n = matrix.size();     // number of rows
  int m = matrix[0].size();  // number of columns

  // top row
  for (int i = r; i < m - r; ++i)
  {
    result.push_back(matrix[r][i]);
  }
  // right column
  for (int i = r + 1; i < n - r; ++i)
  {
    result.push_back(matrix[i][m - r - 1]);
  }
  // bottom row
  for (int i = m - r - 2; i >= r; --i)
  {
    result.push_back(matrix[n - r - 1][i]);
  }
  // left column
  for (int i = n - r - 2; i >= r + 1; --i)
  {
    result.push_back(matrix[i][r]);
  }

  return result;
}

void set_ring(vector<vector<int>>& matrix, vector<int> ring, int r)
{
  int n = matrix.size();     // number of rows
  int m = matrix[0].size();  // number of columns

  int current_element = 0;

  // top row
  for (int i = r; i < m - r; ++i)
  {
    matrix[r][i] = ring[current_element];
    current_element++;
  }
  // right column
  for (int i = r + 1; i < n - r; ++i)
  {
    matrix[i][m - r - 1] = ring[current_element];
    current_element++;
  }
  // bottom row
  for (int i = m - r - 2; i >= r; --i)
  {
    matrix[n - r - 1][i] = ring[current_element];
    current_element++;
  }
  // left column
  for (int i = n - r - 2; i >= r + 1; --i)
  {
    matrix[i][r] = ring[current_element];
    current_element++;
  }
}

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int num_rotations)
{
  int n = matrix.size();     // number of rows
  int m = matrix[0].size();  // number of columns

  int num_rings = min(n, m) / 2;
  // TODO: compute modulo rotations per ring

  for (int r = 0; r < num_rings; ++r)
  {
    vector<int> ring = get_ring(matrix, r);

    int ring_rotations = num_rotations % ring.size();
    rotate(ring.begin(), ring.begin() + ring_rotations, ring.end());

    set_ring(matrix, ring, r);

    /*
    for (int i = 0; i < ring.size(); ++i)
        cout << ring[i] << " ";
    cout << endl;
    */
  }

  for (int row = 0; row < n; ++row)
  {
    for (int col = 0; col < m; ++col)
      cout << matrix[row][col] << " ";
    cout << endl;
  }
}

int main()
{
  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int m = stoi(first_multiple_input[0]);

  int n = stoi(first_multiple_input[1]);

  int r = stoi(first_multiple_input[2]);

  vector<vector<int>> matrix(m);

  for (int i = 0; i < m; i++)
  {
    matrix[i].resize(n);

    string matrix_row_temp_temp;
    getline(cin, matrix_row_temp_temp);

    vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

    for (int j = 0; j < n; j++)
    {
      int matrix_row_item = stoi(matrix_row_temp[j]);

      matrix[i][j] = matrix_row_item;
    }
  }

  matrixRotation(matrix, r);

  return 0;
}

string ltrim(const string& str)
{
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string& str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string& str)
{
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos)
  {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
