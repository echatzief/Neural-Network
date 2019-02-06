let training_data =[
    {
        inputs:[0,0],
        target:[0],
    },
    {
        inputs:[1,1],
        target:[0],
    },
    {
        inputs:[1,0],
        target:[1],
    },
    {
        inputs:[0,1],
        target:[1],
    },
];


function setup(){
    createCanvas(800, 800);

    //Create the neural network
    var brain =new NeuralNetwork(2,30,1);

    for(let i=0;i<10000;i++){
        
       // let data = random(training_data);
        for(data of training_data){
            brain.train(data.inputs,data.target);
        }
        //brain.train(data.inputs,data.target);
    }
   
    console.log(brain.feedForward([0,0]));
    console.log(brain.feedForward([0,1]));
    console.log(brain.feedForward([1,0]));
    console.log(brain.feedForward([1,1]));
}
function draw(){
    background(143, 144, 145);
}