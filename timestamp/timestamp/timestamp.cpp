// timestamp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

/*	Der Zeitgeber - ein Zeitgeber besteht aus einem Startpunkt und einem Zeittakt.
* 
* ->	std::chrono::system_clock - Stellt die natürliche Zeit (wall-clock) dar.
*									Er bietet die Hilfsfunktionen to_time_t und from_time_t an, um Zeitpunkte in Datumsausgaben zu konvertieren. 
* 
* ->	std::chrono::steady_clock - gibt als einziger Zeitgeber die Garantie, dass er nicht neu gestellt werden kann.
*									Damit ist std::chrono::steady_clock die ideale Uhr, um bis zu einem Zeitpunkt oder für eine Zeitdauer zu warten.
* 
* ->	std::chrono::high_resolution_clock - ist der Zeitgeber mit der höchsten Auflösung.
*											 Er kann ein Synonym für den Zeitgeber std::chrono::system_clock oder auch std::chrono::steady_clock sein.
* 
* Windows / Linux
*	-	Die Ausgabe unter Linux und Windows unterscheiden sich.
*		So ist die std::chrono::system_clock unter Linux deutlich genauer, so ist std::chrono::high_resolution_clock unter Windows stetig.
*	-	Unter Linux besitzen sowohl std::chrono::system_clock als auch std::chrono::high_resolution_clock die UNIX-Epoche als Startzeitpunkt.
*		Hingegen ist der Bootzeitpunt der Startzeitpunkt von std::chrono::steady_clock.
*		Unter Windows ist für den Zeitgeber std::chrono::high_resolution_clock im Gegensatz zu Linux der Bootzeitpunkt der Startpunkt.
* 								
*/


/*
* // Die Zeitdauer
#include <chrono>
#include <iostream>

using namespace std;

int main(){

	cout << std::fixed << endl;	// 1.62045e+15 -> 1620454576288213.500000

	cout << "Time since 01.01.1970:\n" << endl;	// UNIX-Epoche

	auto timeNow = std::chrono::system_clock::now();	// auto -or-> std::chrono::system_clock::
	auto duration = timeNow.time_since_epoch();
	cout << " nanoseconds\t" << duration.count() << endl;

	typedef std::chrono::duration<long double, std::ratio<1, 1000000>> MyMicroSecondTick;
	MyMicroSecondTick micro(duration);
	cout << " microseconds\t" << micro.count() << endl;

	typedef std::chrono::duration<long double, std::ratio<1, 1000>> MyMilliSecondTick;
	MyMilliSecondTick milli(duration);
	cout << " milliseconds\t" << milli.count() << endl;

	typedef std::chrono::duration<long double> MySecondTick;
	MySecondTick sec(duration);
	cout << " seconds\t" << sec.count() << endl;

	typedef std::chrono::duration<double, std::ratio<60>> MyMinuteTick;
	MyMinuteTick myMinute(duration);
	cout << " minutes\t" << myMinute.count() << endl;

	typedef std::chrono::duration<double, std::ratio<60 * 60>> MyHourTick;
	MyHourTick myHour(duration);
	cout << " hours\t\t" << myHour.count() << endl;

	typedef std::chrono::duration<double, std::ratio<60 * 60 * 24 * 365>> MyYearTick;
	MyYearTick myYear(duration);
	cout << " years\t\t" << myYear.count() << endl;

	typedef std::chrono::duration<double, std::ratio<60 * 45>> MyLessonTick;
	MyLessonTick myLesson(duration);
	cout << " lessons\t" << myLesson.count() << endl;
}
*/

/*
// Genauigkeit und Stetigkeit

#include <chrono>
#include <iomanip>
#include <iostream>

template <typename T>
void printRatio() {
    std::cout << "  precision: " << T::num << "/" << T::den << " second " << std::endl;
    typedef typename std::ratio_multiply<T, std::kilo>::type MillSec;
    typedef typename std::ratio_multiply<T, std::mega>::type MicroSec;
    std::cout << std::fixed;
    std::cout << "             " << static_cast<double>(MillSec::num) / MillSec::den << " milliseconds " << std::endl;
    std::cout << "             " << static_cast<double>(MicroSec::num) / MicroSec::den << " microseconds " << std::endl;
}

int main() {

    std::cout << std::boolalpha << std::endl;

    std::cout << "std::chrono::system_clock: " << std::endl;
    std::cout << "  is steady: " << std::chrono::system_clock::is_steady << std::endl;
    printRatio<std::chrono::system_clock::period>();

    std::cout << std::endl;

    std::cout << "std::chrono::steady_clock: " << std::endl;
    std::cout << "  is steady: " << std::chrono::steady_clock::is_steady << std::endl;
    printRatio<std::chrono::steady_clock::period>();

    std::cout << std::endl;

    std::cout << "std::chrono::high_resolution_clock: " << std::endl;
    std::cout << "  is steady: " << std::chrono::high_resolution_clock::is_steady << std::endl;
    printRatio<std::chrono::high_resolution_clock::period>();
}
*/

/*
// Epoche
#include <chrono>
#include <iomanip>
#include <iostream>

template <typename T>
void durationSinceEpoch(T dur)
{
    std::cout << "     Counts since epoch:  " << dur.count() << std::endl;
    typedef std::chrono::duration<double, std::ratio<60>> MyMinuteTick;
    MyMinuteTick myMinute(dur);
    std::cout << std::fixed;
    std::cout << "     Minutes since epoch: " << myMinute.count() << std::endl;
    typedef std::chrono::duration<double, std::ratio<60 * 60 * 24 * 365>> MyYearTick;
    MyYearTick myYear(dur);
    std::cout << "     Years since epoch:   " << myYear.count() << std::endl;
}

int main()
{
    std::cout << std::endl;

    std::chrono::system_clock::time_point timeNowSysClock = std::chrono::system_clock::now();
    std::chrono::system_clock::duration timeDurSysClock = timeNowSysClock.time_since_epoch();
    std::cout << "std::chrono::system_clock: " << std::endl;
    durationSinceEpoch(timeDurSysClock);

    std::cout << std::endl;

    auto timeNowStClock = std::chrono::steady_clock::now();
    auto timeDurStClock = timeNowStClock.time_since_epoch();
    std::cout << "std::chrono::steady_clock: " << std::endl;
    durationSinceEpoch(timeDurStClock);

    std::cout << std::endl;

    auto timeNowHiRes = std::chrono::high_resolution_clock::now();
    auto timeDurHiResClock = timeNowHiRes.time_since_epoch();
    std::cout << "std::chrono::high_resolution_clock: " << std::endl;
    durationSinceEpoch(timeDurHiResClock);
}
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <ratio>

using namespace std;

int main()
{
    int i, j, duration = 1000000; // [ns]

    double long ns, istTime = 0, minTime, maxTime, mittTime, sumTime = 0;
    double long ns_1, istTime_1, minTime_1, maxTime_1, mittTime_1, sumTime_1 = 0;
    double long absDev, relDev;


    minTime = istTime;
    maxTime = istTime;

    for (i = 0; i < 10; i++)
    {
        cout << std::fixed << endl;
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        std::chrono::nanoseconds dura(duration); // 1 000 000 [ns] -> 1 000 [us] -> 1 [ms] - 0,001 [s]
        std::this_thread::sleep_for(dura);

        std::chrono::high_resolution_clock::time_point ende = std::chrono::high_resolution_clock::now();

        std::chrono::high_resolution_clock::duration diff = ende - start;
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();
        istTime = ns;

        absDev = (duration - istTime) / 1000000;
        relDev = ((duration - istTime) / duration) * 100;

        cout << "________________________________" << i << endl;
        cout << "istTime\t"  << istTime << " [ns]" << " | " << absDev << " [ms]" << " | " << relDev << " [%]" << endl;

        if (istTime <= minTime || minTime == 0)
        {
            minTime = istTime;
        }
        if (istTime >= maxTime || maxTime == 0)
        {
            maxTime = istTime;
        }
        sumTime = sumTime + istTime;

        std::chrono::high_resolution_clock::time_point start1 = std::chrono::high_resolution_clock::now();
        for (j = 0; j < 100; j++)
        {
            std::chrono::nanoseconds dura(duration); // 1 000 000 [ns] -> 1 000 [us] -> 1 [ms] - 0,001 [s]
            std::this_thread::sleep_for(dura);

            std::chrono::high_resolution_clock::time_point ende1 = std::chrono::high_resolution_clock::now();

            std::chrono::high_resolution_clock::duration diff = ende1 - start1;
            ns_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();
            istTime_1 = ns_1;
            sumTime_1 = sumTime_1 + istTime_1;
        }
        mittTime_1 = sumTime_1 / j;
        cout << "mittTime_1\t" << mittTime_1 << endl;
    }
    mittTime = sumTime / i;
    cout << "mittTime\t" << mittTime << endl;
    mittTime_1 = sumTime_1 / i / j;
    cout << "mittTime_1\t" << mittTime_1 << endl;

}