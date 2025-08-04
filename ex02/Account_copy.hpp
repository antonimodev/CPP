#pragma once

class Account {
	public:
		Account(int initial_deposit);
		~Account(); // Delete Account once we finish with it, save memory

		void	makeDeposit(int deposit);
		bool	makeWithdrawal(int withdrawal);
		int		checkAmount() const;
		void	displayStatus() const;

		static int	getNbAccounts();
		static int	getTotalAmount();
		static int	getNbDeposits();
		static int	getNbWithdrawals();
		static void	displayAccountsInfos();

	// '_' to point private attributes
	private:
		static void	_displayTimestamp();
		static int	_nbAccounts;
		static int	_totalAmount;
		static int	_totalNbDeposits;
		static int	_totalNbWithdrawals;

		int		_accountIndex;
		int		_amount;
		int		_nbDeposits;
		int		_nbWithdrawals;
		Account();
	};