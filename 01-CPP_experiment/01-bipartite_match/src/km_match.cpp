#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define INF 0X3F3F3F3F

class kmMatch
{
public:
    /**
     * @brief member param for km match
     */
    int m_;           // size of set A
    int n_;           // size of set B
    int **map_;       // map of set A and B, with size m x n
    int *ex_A_;       // expectation of set A, size m
    int *ex_B_;       // expectation of set B, size n
    bool *visited_A_; // set A visited, size m
    bool *visited_B_; // set B visited, size n
    int *matched_B_;  // set B matched, size n
    int *slack_B_;    // set B with slack, size n
    int w_min;        // 最小权重

    /**
     * @brief Construct a new km Match object
     *
     * @tparam m
     * @tparam n
     */
    template <int m, int n>
    kmMatch(const int (&map)[m][n]);

    /**
     * @brief clear mem space newed in this class
     *
     */
    void clear();

    /**
     * @brief show data in this class
     *
     */
    void show_data();

    /**
     * @brief start km match, return number of matched pairs
     *
     * @return int
     */
    int match();

    /**
     * @brief match with depth first search
     * 
     * @param setA_i index of set A
     * @return true 
     * @return false 
     */
    bool match_dfs(int setA_i);
};

/**
 * @brief Construct a new km Match object
 *
 * @tparam m
 * @tparam n
 */
template <int m, int n>
kmMatch::kmMatch(const int (&map)[m][n])
{
    // init m, n
    this->m_ = m;
    this->n_ = n;

    // init w_min
    this->w_min = 1;

    // init map mem space
    this->map_ = new int*[this->m_];
    for (int i = 0; i < this->m_; i++)
    {
        this->map_[i] = new int[this->n_];
    }

    // assign map value
    for (int i = 0; i < this->m_; i++)
    {
        for (int j = 0; j < this->n_; j++)
        {
            this->map_[i][j] = map[i][j];
        }
    }

    // init expectation array
    this->ex_A_ = new int[this->m_];
    for (int i = 0; i < this->m_; i++)
    {
        this->ex_A_[i] = 0;
    }
    this->ex_B_ = new int[this->n_];
    for (int i = 0; i < this->n_; i++)
    {
        this->ex_B_[i] = 0;
    }

    // init visited array
    this->visited_A_ = new bool[this->m_];
    for (int i = 0; i < this->m_; i++)
    {
        this->visited_A_[i] = false;
    }
    this->visited_B_ = new bool[this->n_];
    for (int i = 0; i < this->n_; i++)
    {
        this->visited_B_[i] = false;
    }

    // init set B matched array
    this->matched_B_ = new int[this->n_];
    for (int i = 0; i < this->n_; i++)
    {
        this->matched_B_[i] = -1;
    }

    // init set B slack array
    this->slack_B_ = new int[this->n_];
    for (int i = 0; i < this->n_; i++)
    {
        this->slack_B_[i] = 0;
    }
}

/**
 * @brief clear mem space newed in this class
 *
 */
void kmMatch::clear()
{
    // clear map
    for (int i = 0; i < this->m_; i++)
    {
        delete[] this->map_[i];
    }
    delete[] this->map_;

    // clear expectation array
    delete[] this->ex_A_;
    delete[] this->ex_B_;

    // clear visited array
    delete[] this->visited_A_;
    delete[] this->visited_B_;

    // clear set B matched array
    delete[] this->matched_B_;

    // clear set B slack array
    delete[] this->slack_B_;

    // reset m, n
    this->m_ = 0;
    this->n_ = 0;
}

/**
 * @brief show data in this class
 *
 */
void kmMatch::show_data()
{
    // // print m, n
    // std::cout << "m: " << this->m_ << "\n";
    // std::cout << "n: " << this->n_ << "\n";

    // // print map
    // std::cout << "map: \n";
    // for (int i = 0; i < this->m_; i++)
    // {
    //     for (int j = 0; j < this->n_; j++)
    //     {
    //         std::cout << this->map_[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    std::cout << "=============== \n";

    // print expectation array
    std::cout << "ex_A: \n";
    for (int i = 0; i < this->m_; i++)
    {
        std::cout << this->ex_A_[i] << " ";
    }
    std::cout << "\n";
    std::cout << "ex_B: \n";
    for (int i = 0; i < this->n_; i++)
    {
        std::cout << this->ex_B_[i] << " ";
    }
    std::cout << "\n";

    // print visited array
    std::cout << "visited_A: \n";
    for (int i = 0; i < this->m_; i++)
    {
        std::cout << this->visited_A_[i] << " ";
    }
    std::cout << "\n";
    std::cout << "visited_B: \n";
    for (int i = 0; i < this->n_; i++)
    {
        std::cout << this->visited_B_[i] << " ";
    }
    std::cout << "\n";

    // print set B matched array
    std::cout << "matched_B: \n";
    for (int i = 0; i < this->n_; i++)
    {
        std::cout << this->matched_B_[i] << " ";
    }
    std::cout << "\n";
    
    // print set B slack array
    std::cout << "slack_B: \n";
    for (int i = 0; i < this->n_; i++)
    {
        std::cout << this->slack_B_[i] << " ";
    }
    std::cout << "\n";
}

/**
 * @brief start km match, return number of matched pairs
 *
 * @return int
 */
int kmMatch::match()
{
    // init set A expectation with max expectation to set B
    for (int i = 0; i < this->m_; i++)
    {
        this->ex_A_[i] = this->map_[i][0];
        for (int j = 1; j < this->n_; j++)
        {
            this->ex_A_[i] = std::max(this->ex_A_[i], this->map_[i][j]);
        }
    }

    // print set A expectation
    std::cout << "init ex_A: \n";
    for (int i = 0; i < this->m_; i++)
    {
        std::cout << this->ex_A_[i] << " ";
    }
    std::cout << "\n";
    
    
    // try to find match for every element in A
    for (int i = 0; i < this->m_; i++)
    {
        // fill INF in slack_B
        std::fill(this->slack_B_, this->slack_B_+this->n_, INF);
        std::cout << "init slack_B_: \n";
        for (int i = 0; i < this->n_; i++)
        {
            std::cout << this->slack_B_[i] << " ";
        }
        std::cout << "\n";

        int count = 0;
        while (true)
        {
            count++;
            if (count > 10)
            {
                std::cout << "can't find match for set A Nr. " << i << "\n";
                break;
            }

            // reset visited array
            std::memset(this->visited_A_, false, this->m_);
            std::memset(this->visited_B_, false, this->n_);
            // std::cout << "reset visited_A_: \n";
            // for (int i = 0; i < this->m_; i++)
            // {
            //     std::cout << this->visited_A_[i] << " ";
            // }
            // std::cout << "\n";
            // std::cout << "reset visited_B_: \n";
            // for (int i = 0; i < this->n_; i++)
            // {
            //     std::cout << this->visited_B_[i] << " ";
            // }
            // std::cout << "\n";

            // if find match, break loop
            if (match_dfs(i))
            {
                show_data();
                break;
            }

            // 最小可降低期望值
            int d = INF;
            for (int j = 0; j < this->n_; j++)
            {
                // check set B visited
                if (!this->visited_B_[j])
                {
                    d = std::min(d, this->slack_B_[j]);
                }
            }
                        
            // lower the visited set A expectation
            for (int j = 0; j < this->m_; j++)
            {
                if (this->visited_A_[j])
                {
                    this->ex_A_[j] -= d;
                }
            }

            // higher the visisted set B expectation
            for (int j = 0; j < this->n_; j++)
            {
                // visited set B + d
                if (this->visited_B_[j])
                {
                    this->ex_B_[j] += d;
                }
                // no visited set B - d
                else
                {
                    this->slack_B_[j] -= d;
                }
            }

            show_data();

            // manuel control
            // while(true)
            // {
            //     int c;
            //     std::scanf("%d", &c);
            //     if (c == 1)
            //     {
            //         break;
            //     }
            // }
        }
    }
    
    // totoal matched weights
    int res = 0;
    for (int i = 0; i < this->n_; i++)
    {
        if (this->matched_B_[i] != -1)
        {
            std::cout << "set B Nr. " << i << " matches with set A Nr. " << this->matched_B_[i] << "\n";

            // check match weight
            if (this->map_[this->matched_B_[i]][i] < this->w_min)
            {
                std::cout << "this pair is not a proper matched pair.\n";
            }
        
        }
        if (this->matched_B_[i] == -1)
        {
            std::cout << "set B Nr. " << i << " has no match.\n";
            continue;
        }
        res += this->map_[this->matched_B_[i]][i];
    }
    return res;
}

/**
 * @brief match with depth first search
 * 
 * @param setA_i index of set A
 * @return true 
 * @return false 
 */
bool kmMatch::match_dfs(int setA_i)
{
    // check setA_i
    if (setA_i >= this->m_ ||
        setA_i < 0
    )
    {
        std::cout << "wrong setA_i \n";
        return false;
    }
    


    // set visited
    this->visited_A_[setA_i] = true;

    // iterate set B
    for (int setB_i = 0; setB_i < this->n_; setB_i++)
    {
        // skip visited set B
        if (this->visited_B_[setB_i])
        {
            continue;
        }

        // calc gap
        int gap = this->ex_A_[setA_i] + this->ex_B_[setB_i] - this->map_[setA_i][setB_i];

        // check gap
        if (gap == 0)
        {
            // set B visited
            this->visited_B_[setB_i] = true;
        
            // check this set B element is matched or can find another set A element
            if (this->matched_B_[setB_i] == -1 ||
                match_dfs(this->matched_B_[setB_i]))
            {
                // set match
                this->matched_B_[setB_i] = setA_i;
                return true;
            }
        }
        else
        {
            this->slack_B_[setB_i] = std::min(this->slack_B_[setB_i], gap);
        }
    }

    // no match
    return false;
}

/**
 * @brief main
 *
 * @return int
 */
int main()
{
    // init test data
    // int map[3][3] = {
    //     {3, 0, 4},
    //     {2, 1, 3},
    //     {0, 0, 5}};

    // int map[5][5] = {
    //     {0, 0, 3, 4, 0},
    //     {5, 0, 0, 0, 0},
    //     {0, 3, 0, 0, 0},
    //     {0, 0, 6, 2, 0},
    //     {7, 5, 6, 10, 0}};

    // int map[5][5] = {
    //     {7, 5, 6, 10, 0},
    //     {0, 0, 6, 2, 0},
    //     {5, 0, 0, 0, 0},
    //     {0, 0, 3, 4, 0},
    //     {0, 3, 3, 0, 0}};

    int map[5][5] = {
        {7, 5, 6, 10, 0},
        {0, 0, 6, 2, 0},
        {5, 0, 0, 0, 0},
        {0, 0, 3, 4, 0},
        {0, 0, 0, 0, 0}};

    // int map[5][5] = {
    //     {3, 5, 5, 4, 1},
    //     {2, 2, 0, 2, 2},
    //     {2, 4, 4, 1, 0},
    //     {0, 1, 1, 0, 0},
    //     {1, 2, 1, 3, 3}};

    kmMatch km_match(map);
    km_match.show_data();
    std::cout << km_match.match() << "\n";
    km_match.clear();

    return 0;
}