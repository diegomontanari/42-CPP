#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);

	private:
		// Le quattro lamentele: private, perché da fuori si passa sempre da complain
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
