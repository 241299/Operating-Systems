#include <unistd.h>
#include <stdio.h>
#include <sys/signal.h>

void print_johnny();

int main() {
    pid_t pid = fork();

    if ((int) pid) {
        sleep(10);
        print_johnny();
        kill(pid, SIGTERM);
    } else {
        while (1) {
            printf("Child says: \"I'm alive\"\n");
            sleep(1);
        };
    }
}


/**
 * Easter egg for well-known film
 */

void print_johnny() {
    printf("Here's Johnny!\n");
    printf("```yhsoo+/////s+osyo://--....-----------::::::::/++o+..+hy+::-.-s/``.-...://:/::-.`.`   ``` ``  ``                   ````````      `   ` ``  `````````\n"
           "``.mdysoo++++/+/+/yo:::-...----.--------:::::::://+oo..+hhyo:-..://..-...///://///--.   `.` ``  ``                 ``` ````  ``````````    ```````````\n"
           "``-mmdhyso++/+////yo+::--.------------:-:::::::////+s-./yhyy+/-.` ``.....:+/://////:-.` `.` ``  ```            ```````````````````````````   `````````\n"
           "``-mmdhyso++++//::s/o------::--------::::::::::////+o/`:hdyy/:.``   ...`.:++:////////:-```` ``  ``` `       ``./oyyyyyo+/-`````````````````` `````````\n"
           "``/NNmdhsoooo+////oo:/--..-------::---:::::::::::::/+o.:yhyy+-.``   `..``-++::+++/////:-..````  ``` `    ```+dNNNNNNNMMNNNms/`````````````````````````\n"
           "``+Nmmdhsoo+++/////s++:----------::---::::::-::::::/+s--odyys/-``   `..``-+/-:+o++////::-.````` ```      `:hNmmNmmmmdmmMMMMNNmy:``````````````````````\n"
           "``oNmdhysooo+//:/::++//::::-::::-::::::/++//::::::://o--/dyyys:``   `-.``.//--+soo++///:--.```` ```  `   .sNNsommhhmddsdNMMMMNNNy-````````````````````\n"
           "..odhsooo+o++/osssssyyysssssooooo+////++osoossooyyhhhy:-:dhhyy:.`   `-.`..//-./yyso++/::--..``` ```   `  `sNmso//-+sods+odNMMMMMNm+```````````````````\n"
           "..+sooo++oosyhddhhhdmmmmmmmddhyyysooossssyhdmmmmmdhyyho::dhhhy/.`  ``-.`..//-.:shyo++//::----.` ```      `sNhyyo--:++o/:--/dNMMMNNNs.`````````````````\n"
           "..:o+++oooyhdddddddhhddmmmmmmmmdhso++oyyhdddddhysssyyy+--dhhhyo.`   `--`../+:-/yhys++///::--::.````  ``  `oNmddo--.----....-hNMMNMNmh-````````````````\n"
           "``-/++++oshmdmmmmmmmhyyyNNmmdmdhy+:://sdhhhddhsymNNmmms--ddhhys.`  ``--.--ossyhhyso//////:---::.```  ``  `oNNhoosoo::--.....-hMMMMMmmh-```````````````\n"
           ".`-:ooooshddmmmmdyo/:--+hddhysyss+/-::oyyyyo----hdddmms-.hhhhy:..   `-:-++hdddhyso+/////////::/:.``  ``  `sMmo+o+///-.---....hNMMMMNNms..`````````````\n"
           "..--/++oossssso+++/++++osysoooooo+/::::+/++++++oo++osy+-.hdhys:.-```./oshdhhhyso+//::::/++////:/-.`  ``` `sNNy++shdmmy/-----+hNMMMMMNNd-.`````````````\n"
           "..-.:+++++++++oosyyyssyyssoo++o++++/:::/++osyyyyyso++o/..ydyso.`.``./yddhyooo++///::---:++////::/:.` `````oNMmsosdNMMMNs--.-:yNMMMMMMNNs...```````````\n"
           "..---/++++o+//::-::///////:/+++++oo/:-::/+///////:::/o/..ydyss...`.-sddyo+//:::::::---:/+++///::::-````  `oNMMmsosdMNNmy:----dNMMMMMMMNNh:.```````````\n"
           "..-./ooo++++/+///:-----:::::++o++++/:---:++//:::::-::+--.ydyys...``.+yso//:::::----::::/++//:::::::.```  `+NMMMNhosdo++o::--/NMMMMMMMMMMNNy:``````````\n"
           "..:-/ooo++//////::------:/+++//:/+/:-.---///+o+/:::-:+-..ydhyy-.````-+//:---::------:::////::::::---```` `:NMMMMMNysyhy+/:-:yMMMMMMMMMMMMNNNh+:..-.-//\n"
           "..:-+osoo++///////:::/oyhhyyooyyyyys+++//+ssshhso//::/.-.ydhyy-...`.-::------:::----:/::://::::/:---.``` `:NMMMMMMMdsooooo++dMMMMMMMMMMMMMMMNNdhhhhy/.\n"
           "..:/yosssoo+++++++++oyhhyyydddddmNmmdhhhhdmdhshhys+///.--hdhys/-://+/::::---://::::::/::::::::::-----.`` `:mMMMMMMMMdhhyysydNMMmNMNmmmmMMMNhyyyyyysoss\n"
           "..:+hyssssooo+oooosshhhyyyyhhhhhhdmmmmmmmmdhyssyhyo++/.--hdhyo++++oo+/::::::///:::::///:::::::-------..`  -sNMMMMMMMMddddmmmNMNmNNmmmNNMMNdhdddhhhyyso\n"
           "..::yhyyssssssssssyhdhhhhhhhhhhhhyhdmmmmdhhhyhhhdysso/--:yyso+oooooo++/::://::::///////::::::---------..``:./mMMMMMMMmdddhddmMMMNmmmmNMMNmmmNmmdhhhhhy\n"
           "..:/sdhhyyyssssysyhdhhhhhhhhhhhhhyyyhhhhhhyhhddhdhyss+.--ssoooooooooo++/::/:::://///////::::-----------..`./.-hMMMMMMMmdmdmmNNNNmmmmNNMMNNNNmmdmmddhhh\n"
           "..//oddhhysyysssyhhhhhyhhhdhhdyhhsyysoyoyoddhyhhdhysy+.--ooossssoooo+++///:::::++////::::::-------------...-/-oMMMMMMNNhooydMNNNmmNNNMMMNNNmmmmmmddddd\n"
           "..//+dddhhyyssooshyyyyhdmmy/-:..-..-`.-`-.sNmdhyhyssh/.:-osssssoooo+++++//:::::/+///:::::::---:::------::-..-:/MMMMMMMmhmyNMMMNNNNNNMMNMNNNNNNNmmmmmdd\n"
           ".-///mdddhhyysoooysyyhmNmdhdshsss++o+oyydmNNdsyssoood:.:-oyyyssoooo++oo++//:////+/::::::::::-://:----:::::-..--mMMNMMMMdmMNNNNNNNNNMNNMNNNNNNmmmmmmmdh\n"
           ".-///Nmdddhhyyso+o++oohmdhhhhyhhddddddddmhodhsooo+oym-.::yhhyssoooooooooo+://///+//:::::::::::::::--::::/::-..-mMMNNMMMMMNNNNNNNNmNNmNNNNNNmmNmmmmNmdd\n"
           ".-///NNmmdhhhhys+++/+oso-.-/o+/+///+//:/../hsso+++odm-.-:ydyyssooooossso+/::////////::::::///::-::::::://::--.-mMMNNMMMNmNNMNNNNNNNmNNNNNNNmmmmmNNNmdd\n"
           ".-://NNNNddhhhdhs+++//ooo/:.-..:.--:-:-:-/ososo+/oymm-.-:ydyyssssssssso+//::/:::////:::::///:::::///:::::::---./mNNNNNNNNNMMMNNNNNNNNNNNNNNmmmmmNNmmdh\n"
           ".-:/+NNNNNmddhddhyo+o++osysoo+//:++/++/ooosssooo+smNN:.--ydhhyyyys/ooo++/+/://:////:::::////:::::///////::::---.-sdmNNMNMNNMMMNNNNNNMMNMNNmmNNNNmmmmdh\n"
           ".://yNNNMMMNmddddhso+ooosssssso+++ooo+osssssooooydNNN-.--hmdhyysso.:+++++/-://///////////////:::://+/::::::::::---sddmmmNNNMMMNNNNNNMMMNNNNNNmmmmmmmdh\n"
           ".://yNNNMMMMNNmmddhysooo+osyyyyyyssssssyyssooosshmNMm..-:yhyssssy/-+o++o+-.-/+///////+////::::::::///::::::::::::::sdddmmNMMMMNMMNNMMMNNNNNNNNmmmmmmdh\n"
           "./:+oNNMMMMMMMNmmmddhsso++++osooossssssoo++++osydNMNy..-:/:./osso++o+++/:..-/////////++///::::::::::::::::::::://///sdmNNNMMMNNMMMMMMMMMNNNNNmNNmmmmdh\n"
           ".-:+oNNNNMMMMMMNNNmmmdysso+/+++/+///+++/+++oosydNMNm/..-:.``../o++o+///:.``.///////////////:::::::::::::::///////+osyhmmNmmmmmmNMMMMNNNNNNNNNNNNmmmmdh\n"
           ".://hNMMMNNMMMMMMMNNNmdhyyyoo+++++/+o/+++ooosymNMMNd-..-:`````./o+/////:``..:////:////////::::::::::::::://////+osydmmmmmmmmNmdmmmNMMMMMMMMMMNNNNmmmmh\n"
           "-://mNNNNNNNNMMMMMMMNNNNmddhyysosysssssoossyhmMMMMNd-...-`````.://///:/-``..:///:://///////::///:::::///////++oshddmNNNmmmmNNNmmdddmNNmNNNNNNMMNNNmmmd\n"
           ":://dNNNMNNmNNNMMMMMMMMNNNNmmddhhyhhdhhhhhdmNMMMMMNy...-:``````-//:/:/:.``..:///::://////////////::::://////oyddmNNNNMNmmmmmNNNmmddmmNmNmNmmmmNMMMNNmd\n"
           "-:/:dNNMNNNmmmmmNNMMMMMMMMMMNNNNNmmmmmNNNNNMMMMMMMMN+-..-``````-/:::::-```..:::/://::////////////////////:--omNMMNNmNMMMNmdmmNNNmmmmmmdNmNNmmmmmNMMNmd\n"
           "-:/:mNNNNmNNmmmmmmNNNNNMMMNMMMMMMMMMMMMMMMMMMMMMMNMMNo.-:``````-//::::-`....:::://::::://////:////////:::.`.+MMMdhysydNMMNNmmmmmmmmmNNmNNmNNdmNNmmNMNd\n"
           "-:/:dmNNNNNNNmdddddmNNNNNNNNNNMMMMMMMMMMMMMMMMMMMNNNm/:.:``````:+:/+::-`....::::///::::://///////:/::-.--``./Nmso///:::smMMNNNNNNmmmmMNmMNmNmmmNNmmmmd\n"
           "://:hmNNNMNNMNmmdddddmNNNNNNNNNMMMMMMMMMMMMMMMMMNNNN/..-:``````::+s/::.`....:::://:::://////////:----.``.```+Nd++//:--::-yMMMMNNNNNmdNMNNMMNNmmmNNNNmd\n"
           ":-/:hNNNNNMNNNmmdddddddmNNNNNNNMMMMMMMMMMMMMMMMNNNmm+...:``````:oh+:::``....:::://::::///::::--:-``..```.```+Ny//oo+:-sy+/dmmNNNNNNmddmNmNMMNNmmmNNmdN\n"
           "-/:-hNNNNNNNNMmmdddddhhdmmmNNNNNNNNNNMMMMMMMMMMNNNNN+..-:``````:dy/::-``....:::-://:::::--.--..--``..```.```sNosyyy+/:mNMMd/:::::://///++osydNNmmmmmmM");
}