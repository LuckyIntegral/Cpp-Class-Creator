
#pragma once

#ifndef AA_HPP
# define AA_HPP

# include <string>

class aa {
public:
    aa();
    aa( const aa &other );
    ~aa();

    aa &operator=( const aa &other );
};

#endif // AA_HPP

