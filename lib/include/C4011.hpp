//
// C4011.hpp for nano in /home/galibe_s/rendu/cpp_nanotekspice/src/component
// 
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
// 
// Started on  Sat Feb 13 14:17:21 2016 stephane galibert
// Last update Sat Feb 13 20:36:45 2016 stephane galibert
//

#ifndef _C4011_HPP_
# define _C4011_HPP_

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
  class C4011 : public IComponent
  {
  public:
    C4011(std::string const& value);
    virtual ~C4011(void);
    
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

#endif /* !_C4011_HPP_ */
