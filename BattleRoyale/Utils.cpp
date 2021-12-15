#include "Utils.h"
#include <random>

const array<array<int, 2>, 4> Utils::DIRECTIONS = { {{1,0},{0,1},{-1,0},{0,-1}} };

const string Utils::SILLY_NAMES[120] =
{	"Abuzz Heartbreaker",
	"Alphabetic Afterimage",
	"Anony Mouse",
	"Arabic Denial",
	"Ass Ass In",
	"Ass Whupper",
	"Ayam Taken",
	"Bad Karma",
	"BeenThere DoneThat",
	"Behind You",
	"Ben Dover",
	"Berb DiWire",
	"Blurry Image",
	"Born Confused",
	"Bros Before Hoes",
	"Butt Smasher",
	"Casanova",
	"Cementitious Day",
	"Cereal Killer",
	"Counterclockwise Chi",
	"Cover Boy",
	"Cuddly Goblin",
	"Depressing Mistake",
	"Dildo Swaggins",
	"Dumbest Man Alive",
	"Endogamous Gnetum",
	"Epic Fail",
	"Erectile Reptile",
	"Google MeNow",
	"Grammar Jew",
	"Hakuna Matata",
	"HeirToThe PubicRegion",
	"HerpesFree Since03",
	"Hershey Squirts",
	"Hey You",
	"HeyYou NotYouYou",
	"Hitlersaurus Christ",
	"How You Doing",
	"Hugs for Drugs",
	"ImaComplete CyclePath",
	"Image Not Uploaded",
	"InJail OutSoon",
	"Intelligent Zombie",
	"Intradouching Myshelf",
	"Itchy And Scratchy",
	"James Blonde",
	"JeanClaude VanDarnItAll",
	"Jesus HentaiChrist",
	"Juilius Sneezer",
	"Justin Case",
	"KingOf Diary Queen",
	"Kiss My Axe",
	"Laugh TillYouPee",
	"Liu Kang Baking A Pie",
	"Magic Fetus",
	"Malice Aforethought",
	"Mechanic Mike",
	"My Name Is",
	"MyName IsInUse",
	"MyName Rocks",
	"Name NotImportant",
	"Nameless Faceless",
	"No Child Support",
	"Nonrecreational Filth",
	"Noway Out",
	"Once UponADime",
	"Oprah Windfury",
	"Period Blood",
	"Photo Coming Soon",
	"Pluralizes Everythings",
	"aDistraction",
	"Postmenopausal Spree",
	"Prince Charming",
	"Random Advice",
	"Real Name Hidden",
	"Russian Spy",
	"Say My Name",
	"Shaquille Oatmeal",
	"Sloppy Mcfloppy",
	"Sloppy Wet",
	"SwipeRight ForMe",
	"Tea Baggins",
	"Test Name",
	"That�s Me",
	"The Rapist",
	"This AintMe",
	"Uncommon Name",
	"Uncompartmented Bob",
	"Unfinished Sentenc",
	"Unmodified Workman",
	"Unobjectionable Pawn",
	"WellEndowed Penguin",
	"Whatcha LookingAt",
	"Who Am I?",
	"Willy Wanka",
	"WreckTangle",
	"Wretched Me",
	"XBOX Signout",
	"You Suck",
	"Zero Chills",
	"Queef Latina",
	"fast and the curious",
	"Shaquille UNIEL",
	"The Entire Population of Texas",
	"OwenWilsonsNose",
	"BadKarma",
	"Google Was My Idea",
	"Fedora the explorer",
	"YellowSnowman",
	"AllGoodNamesRGone",
	"thegodfatherpart4",
	"kentuckycriedfricken",
	"bigfootisreal",
	"fatBatman",
	"PaniniHead",
	"Bread Pitt",
	"Ariana Grandes Ponytail",
	"Bud Lightyear",
	"crazy cat lady",
	"Tin foil hat"};

int Utils::randomRange(int start, int end) {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> distrib(start, end);
	return int(distrib(rng));
}