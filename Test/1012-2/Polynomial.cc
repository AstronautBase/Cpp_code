#include "Polynomial.h"
#include <assert.h>

Polynomial::Polynomial(const vector<int> &coefficients)
{
    coefficients_ = coefficients;
}

Polynomial::Polynomial(const Polynomial &other)
{
    this->coefficients_ = other.coefficients_;
}

Polynomial add(const Polynomial &p1, const Polynomial &p2)
{
    // TODO
    Polynomial res;
    if (p1.coefficients_.size() < p2.coefficients_.size())
    {
        res.coefficients_ = p2.coefficients_;
        int diff = p2.coefficients_.size() - p1.coefficients_.size();
        for (int i = 0; i < p1.coefficients_.size(); ++i)
        {
            res.coefficients_[i + diff] += p1.coefficients_[i];
        }
    }
    else
    {
        res.coefficients_ = p1.coefficients_;
        int diff = p1.coefficients_.size() - p2.coefficients_.size();
        for (int i = 0; i < p2.coefficients_.size(); ++i)
        {
            res.coefficients_[i + diff] += p2.coefficients_[i];
        }
    }
    return res;
}

Polynomial derivate(const Polynomial &p)
{
    // TODO
    Polynomial res;
    for (int i = 0; i < p.coefficients_.size() - 1; ++i)
    {
        res.coefficients_.push_back(p.coefficients_[i] * (p.coefficients_.size() - i - 1));
    }
    return res;
}

void Polynomial::output() const
{
    // TODO
    if (coefficients_.size() == 0)
    {
        cout << endl;
    }
    // 系数都为0
    bool all_zero = true;
    for (int i = 0; i < coefficients_.size(); ++i)
    {
        if (coefficients_[i] != 0)
        {
            all_zero = false;
            break;
        }
    }
    if (all_zero)
    {
        cout << endl;
        return;
    }
    for (int i = 0; i < coefficients_.size(); ++i)
    {
        if (coefficients_[i] != 0)
        {
            cout << coefficients_[i] << "(" << coefficients_.size() - i - 1 << ")" << " ";
        }
    }
    cout << endl;
}