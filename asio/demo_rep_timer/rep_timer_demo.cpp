#include <iostream>
#include <basic_repeating_timer.hpp>

void OnRepTimer(boost::system::error_code const& error)
{
	if (!error)
	{
		std::cout << "Tick" << std::endl;
	}
}

void OnTimer1(boost::system::error_code const& error)
{
	if (!error)
	{
		std::cout << "Bong1" << std::endl;
	}
}

void OnTimer2(boost::system::error_code const& error)
{
	if (!error)
	{
		std::cout << "Bong2" << std::endl;
	}
}

void OnTimer3(boost::system::error_code const& error)
{
	if (!error)
	{
		std::cout << "Bong3" << std::endl;
	}
}

int main(void)
{
    boost::asio::io_context io_ctx;

    boost::asio::deadline_timer test_timer_1(make_strand(io_ctx));
    boost::asio::any_io_executor ex = test_timer_1.get_executor();
    boost::asio::any_io_executor ex2 = make_strand(io_ctx);

    boost::asio::deadline_timer test_timer_2(ex);
    boost::asio::deadline_timer test_timer_3(ex2);

    boost::asio::any_io_executor ex3 = make_strand(io_ctx);
    boost::asio::repeating_timer rep_timer_1(ex3);

	std::cout << "Starting some timers..." << std::endl;

	test_timer_1.expires_from_now( boost::posix_time::milliseconds(2900) );
    test_timer_1.async_wait(OnTimer1);
	test_timer_2.expires_from_now( boost::posix_time::milliseconds(900) );
    test_timer_2.async_wait(OnTimer2);
	test_timer_3.expires_from_now( boost::posix_time::milliseconds(1900) );
    test_timer_3.async_wait(OnTimer3);

    rep_timer_1.start( boost::posix_time::milliseconds(1000), OnRepTimer );

	boost::asio::io_service::work work(io_ctx);  // force io_ctx to keep running until explicitly stopped
    io_ctx.run();

	std::cout << "Timers are running" << std::endl;
    for(;;) {}
}

