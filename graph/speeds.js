// 971698 txs (443973598 bytes)

var data = {
    labels : ["LevelDB #1", "LevelDB #2", "100000 (800 Kb)", "1000000 (8 Mb)", "250000000 (2000 Mb) #1", "repeat #2"],
    datasets : [
        {
            fillColor: "rgba(70,119,227, 0.2)",
            strokeColor: "rgba(70,119,227, 1)",
            data: [136770, 158970, 128594, 130399, 129995, 145165]
        },
        {
            fillColor: "rgba(193,181,168, 0.2)",
            strokeColor: "rgba(193,181,168, 1)",
            data: [371222, 353471, 134232, 108943, 102840, 108052]
        },
    ]
}

var ctx = document.getElementById("myChart").getContext("2d");

new Chart(ctx).Bar(data, {});


