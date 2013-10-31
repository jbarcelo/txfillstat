// 971698 txs (443973598 bytes)

var data = {
    labels : ["LevelDB #1", "LevelDB #2", "100000 (800 Kb)", "1000000 (8 Mb)", "250000000 (2000 Mb) #1", "repeat #2", "null"],
    datasets : [
        {
            fillColor: "rgba(70,119,227, 0.2)",
            strokeColor: "rgba(70,119,227, 1)",
            data: [136770, 158970, 128594, 130399, 129995, 145165, 0]
        },
        {
            fillColor: "rgba(193,181,168, 0.2)",
            strokeColor: "rgba(193,181,168, 1)",
            data: [371222, 353471, 134232, 108943, 102840, 108052, 0]
        },
    ]
}

// leveldb #2 was done with 25 #1
// leveldb #3 was done with 25 #2
var data2 = {
    labels : ["LevelDB #1", "LevelDB #2", "LevelDB #3", "LevelDB #4", "LevelDB #5", "LevelDB #6", "100000000 PL (800 Mb) #1", "repeat #2", "250000000 (2000 Mb) #1", "repeat #2", "250000000 PL (2000 Mb)", "800000000 (6400 Mb)", "null"],
    datasets : [
        {
            fillColor: "rgba(193,181,168, 0.2)",
            strokeColor: "rgba(193,181,168, 1)",
            data: [718636, 550587, 442590, 494776, 544661, 443660, 266329, 390161, 327551, 377763, 445948, 469852, 0]
        },
    ]
}

var ctx = document.getElementById("myChart").getContext("2d");

new Chart(ctx).Bar(data, {});

var ctx = document.getElementById("myChart2").getContext("2d");

new Chart(ctx).Bar(data2, {});


