//
// C4081.hpp for nano in /home/galibe_s/rendu/cpp_nanotekspice/src/component
// 
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
// 
// Started on  Wed Feb 10 19:44:38 2016 stephane galibert
// Last update Sat Feb 13 20:16:18 2016 stephane galibert
//

#ifndef _C4081_HPP_
# define _C4081_HPP_

# include <iostream>
# include <string>
# include <utility>
# include <map>
# include <functional>

# include "IComponent.hpp"
# include "Output.hpp"
# include "Exception.hpp"

namespace nts
{
  class C4081 : public IComponent
  {
  public:
    C4081(std::string const& value);
    virtual ~C4081(void);
    
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

    Tristate compute_and(nts::Tristate lhs, nts::Tristate rhs) const;

    nts::Tristate computeInput(size_t pin) const;
    nts::Tristate computeOutput(size_t pin) const;
    nts::Tristate computeVDD(size_t pin) const;
    nts::Tristate computeVSS(size_t pin) const;
  };
}

#endif /* !_C4081_HPP_ */
