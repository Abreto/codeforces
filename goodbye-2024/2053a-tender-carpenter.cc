#include <iostream>
#include <iomanip>
#include <algorithm>

void ioinit()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(10);
}

bool solve(void)
{
    constexpr int MAXN = 256;
    int n;
    int a[MAXN];

    bool possible = false;

    auto possible_by = [&](int pos) -> bool
    {
        int cmax = a[pos], cmin = a[pos];
        for (int i = pos - 1; i >= 0; i--)
        {
            cmax = std::max(cmax, a[i]);
            cmin = std::min(cmin, a[i]);
            if (cmin + cmin > cmax)
            {
                return true;
            }
        }
        return false;
    };

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];

        possible |= possible_by(i);
    }

    return possible;
}

int main(void)
{
    ioinit();

    int t;
    std::cin >> t;

    while (t--)
    {
        if (solve())
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
