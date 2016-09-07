//
// C4017.hpp for  in /home/avelin_j/Work/cpp_nanotekspice/lib/include
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun Feb 21 14:47:11 2016 avelin_j
// Last update Sun Feb 21 16:03:39 2016 avelin_j
//

#ifndef _C2716_HPP_
# define _C2716_HPP_

# include <iostream>
# include <string>
# include <utility>
# include <map>
# include <functional>

# include "IComponent.hpp"
# include "Exception.hpp"
# include "Output.hpp"

namespace nts
{
  class C2716 : public IComponent
  {
  public:
    C2716(std::string const& value);
    virtual ~C2716(void);

    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target);
    virtual void Dump(void) const;
  private:
    IComponent *_pin[14];
    std::map<size_t, size_t> _lnk;
    std::map<size_t, std::function<Tristate(size_t) > > _mapPin;
    std::map<size_t, std::pair<size_t, size_t> > _mapOutput;

    Tristate compute_nand(nts::Tristate lhs, nts::Tristate rhs) const;

    nts::Tristate computeInput(size_t pin) const;
    nts::Tristate computeOutput(size_t pin) const;
    nts::Tristate computeVDD(size_t pin) const;
    nts::Tristate computeVSS(size_t pin) const;
  };
}

#endif /* !_C2716_HPP_ */
