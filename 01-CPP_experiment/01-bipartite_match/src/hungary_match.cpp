#include <iostream>
#include <cstring>

/**
 * @brief class hungary match
 *
 */
class hungaryMatch
{
public:
    /**
     * @brief member param for hungary match
     */
    int m_;         // number of boy
    int n_;         // number of girl
    int **map_;     // 2d-array for boy-girl-crush
    int *pair_;     // array for paired girl with boy's index
    bool *visited_; // array for visited girl

    /**
     * @brief Construct a new hungary object
     *
     * @tparam m number of boy
     * @tparam n number of girl
     */
    template <int m, int n>
    hungaryMatch(const int (&map)[m][n]);

    /**
     * @brief start match
     *
     * @return int, return number of matched pairs
     */
    int match();

    /**
     * @brief recursively match boy and girl
     *
     * @param i index of current boy
     * @return true
     * @return false
     */
    bool match_recursive(const int i);

    /**
     * @brief show member data
     *
     */
    void show_member_data();

    /**
     * @brief clear mem space newed in this space
     *
     */
    void clear();
};

/**
 * @brief Construct a new hungary object, init member data
 *
 * @tparam m number of boy
 * @tparam n number of girl
 */
template <int m, int n>
hungaryMatch::hungaryMatch(const int (&map)[m][n])
{
    // asign m, n
    this->m_ = m;
    this->n_ = n;

    // init map space
    this->map_ = new int *[this->m_];
    for (int i = 0; i < this->m_; i++)
    {
        this->map_[i] = new int[this->n_];
    }

    // assign map
    for (int i = 0; i < this->m_; i++)
    {
        for (int j = 0; j < this->n_; j++)
        {
            this->map_[i][j] = map[i][j];
        }
    }

    // init pair_
    this->pair_ = new int[this->n_];
    for (int i = 0; i < this->n_; i++)
    {
        // 初始化每个女生对应的男生编号为-1, 即没有男生与之匹配
        this->pair_[i] = -1;
    }

    // init visited_
    this->visited_ = new bool[this->n_];
    for (int i = 0; i < this->n_; i++)
    {
        // 初始化每个女生被访问的状态为false, 即都没有被访问过
        this->visited_[i] = false;
    }
}

/**
 * @brief show member data
 *
 */
void hungaryMatch::show_member_data()
{
    // print m, n
    std::cout << "m: " << this->m_ << "\n";
    std::cout << "n: " << this->n_ << "\n";

    // print map
    std::cout << "map: \n";
    for (int i = 0; i < this->m_; i++)
    {
        for (int j = 0; j < this->n_; j++)
        {
            std::cout << this->map_[i][j] << " ";
        }
        std::cout << "\n";
    }

    // print pair
    std::cout << "pair: \n";
    for (int i = 0; i < this->n_; i++)
    {
        std::cout << this->pair_[i] << " ";
    }
    std::cout << "\n";

    // print visited
    std::cout << "visited: \n";
    for (int i = 0; i < this->n_; i++)
    {
        std::cout << this->visited_[i] << " ";
    }
    std::cout << "\n";
}

/**
 * @brief start match
 *
 * @return int, return number of matched pairs
 */
int hungaryMatch::match()
{
    // 初始化匹配计数器
    int match_count = 0;

    // 遍历所有男生
    for (int i = 0; i < this->m_; i++)
    {
        // 每次遍历, 设置所有女生访问状态为false
        for (int j = 0; j < this->n_; j++)
        {
            this->visited_[j] = false;
        }

        // 当前男生是否成功匹配
        if (match_recursive(i))
        {
            // 匹配成功, 则计数器加1
            match_count++;
        }
    }

    // print result
    std::cout << "match count: " << match_count << "\n";
    for (int i = 0; i < this->n_; i++)
    {
        std::cout << "girl Nr." << i << " matched with boy Nr." << this->pair_[i] << "\n";
    }

    // 返回匹配计数器
    return match_count;
}

/**
 * @brief recursively match boy and girl
 *
 * @param i index of current boy
 * @return true
 * @return false
 */
bool hungaryMatch::match_recursive(const int i)
{
    // 遍历所有女生
    for (int j = 0; j < this->n_; j++)
    {
        // 如果当前女生未被访问过, 且当前男生与当前女生互有好感
        if (!this->visited_[j] &&
            this->map_[i][j] == 1)
        {
            // 设置当前女生被访问
            this->visited_[j] = true;

            // 如果当前女生没有匹配的男生, 或者该女生的男生找到了新的匹配
            if (this->pair_[j] == -1 ||
                match_recursive(this->pair_[j]))
            {
                // 当前男女匹配成功,
                this->pair_[j] = i;

                // 返回匹配成功
                return true;
            }
        }
    }

    // 循环结束, 匹配失败
    return false;
}

/**
 * @brief clear mem space
 *
 */
void hungaryMatch::clear()
{
    // clear map
    for (int i = 0; i < this->m_; i++)
    {
        delete[] this->map_[i];
    }
    delete[] this->map_;

    // clear visited
    delete[] this->visited_;

    // clear pair
    delete[] this->pair_;

    // reset m, n
    this->m_ = 0;
    this->n_ = 0;
}

/**
 * @brief main
 *
 * @return int
 */
int main()
{
    // // init test data
    // int map[4][4] = {
    //     {1, 1, 0, 0},
    //     {0, 1, 1, 0},
    //     {1, 1, 0, 0},
    //     {0, 0, 1, 0}};

    // init test data
    int map[6][7] = {
        {0, 1, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 0, 6},
        {0, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 1}};

    hungaryMatch hungary_match(map);
    hungary_match.show_member_data();
    hungary_match.match();
    hungary_match.clear();
    hungary_match.show_member_data();

    return 0;
}