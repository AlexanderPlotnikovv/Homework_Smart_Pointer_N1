#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    auto clone()
    {
        std::vector<double> _down;
        std::vector<double> _upper;
        std::vector<double> _middle;
        auto smartptr = std::make_unique<tridiagonal_matrix>(_down, _upper, _middle);
        smartptr->m_down = m_down;
        smartptr->m_upper = m_upper;
        smartptr->m_middle = m_middle;
        return smartptr;
    }
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();
    for (auto elem : matrix_clone->m_down)
    {
        std::cout << elem << " ";
    }
    return 0;
}