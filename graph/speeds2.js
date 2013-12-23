// 971698 txs (443973598 bytes)

var data = {
    labels : ["LevelDB", "LevelDB", "LevelDB", "LevelDB", "LevelDB", "mmht", "mmht", "mmht", "mmht", "mmht", "mmht", "mmht", "mmht", "mmht", "mmht", "mmht", "null"],
    datasets : [
        {
            fillColor: "rgba(70,119,227, 0.2)",
            strokeColor: "rgba(70,119,227, 1)",
            data: [11560587.436745, 11498751.139852, 11476653.582037, 11537438.511248, 11608247.779545, 3742541.679747, 3812239.124599, 3812239.124599, 4264877.040213, 4076303.309067, 3906960.197697, 4201180.739837, 4148791.956055, 4468112.821426, 4584560.933978, 4539420.960732, 0]
        },
    ]
}

// leveldb #2 was done with 25 #1
// leveldb #3 was done with 25 #2
var data2 = {
    labels : ["LevelDB", "LevelDB", "LevelDB", "mmht", "mmht", "mmht", "mmht", "mmht", "null"],
    datasets : [
        {
            fillColor: "rgba(193,181,168, 0.2)",
            strokeColor: "rgba(193,181,168, 1)",
            data: [3840856.001088, 3798562.747261, 4282579.331838, 565755.291407, 570697.646127, 569347.122214, 604217.709083, 566452.240837, 0],
        },
    ]
}

var ctx = document.getElementById("myChart").getContext("2d");

new Chart(ctx).Bar(data, {});

var ctx = document.getElementById("myChart2").getContext("2d");

new Chart(ctx).Bar(data2, {});


