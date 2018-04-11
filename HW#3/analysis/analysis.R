#@author: Chase gregory
#Nar: Statistical Analysis on Triple Sum algorithm

#function Declariation
PdfHist <- function(timeData, fileName){
    #initalize data to NULL (r is "typless" (losely typed))
    data <- NULL
    for(i in 1:nrow(timeData)){
	data <- c(data, timeData[i, 1])
    }
    table <- table(data)
    timeTable <- cbind(table)
    #XXX.csv file to frequency table
    
    pdf(fileName) #opens and creates a pdf file for writing
    barplot(table, #write the barplot data to the pdf
            xlab= "Time (seconds)", #set the x axis title
            ylab= "Solutions Found", #set the y axis title
            main= fileName) #set the title to the file name so we can differentiate between the charts
    basura <- dev.off() #close the pdf...we're done here
    #Keeps the dev.off() function from spewing garbage (basura = garbage in spanish)
    print("NEXT!")
    return(NULL)
}

PropData <- function(to, from, colu){
	for(i in 1:nrow(from)){
		to <- c(to, from[i, colu])
	}
	return(to)
}

ScatterPlot <- function(x, y, fileName){
    exponential.model <- lm(log(x)~y)
    counts.exponential2 <-exp(predict(exponential.model))
    pdf(fileName) 
    print(length(x))
    print(length(y))
    plot (x, y,
          main="Solutions Found v Run Time",
          xlab= "Time (seconds)",
          ylab= "Set Size")
#    abline(lm(x~y), col="red")
    lines(x, counts.exponential2, col="red")
    basura <- dev.off()
    return(NULL)
}
# "main()"{

#read in data as a .csv file (stats file)
timeDataFile<- read.csv(file="/home/CS/c794990g/385DS/HW#3/analysis/TimeData.csv", header=TRUE)


 cntData <- NULL
 timeData <- NULL
 
 cntData <-PropData(cntData, timeDataFile, 1)
 timeData <- PropData(timeData, timeDataFile, 2)
 
 print(timeData)
 print(cntData)
 
 basura <- ScatterPlot (cntData, timeData, "TimeDataN.pdf")
 
 timeDataFile<- read.csv(file="/home/CS/c794990g/385DS/HW#3/analysis/TimeData1-5000.csv", header=TRUE)


 cntData <- NULL
 timeData <- NULL
 
 cntData <-PropData(cntData, timeDataFile, 1)
 timeData <- PropData(timeData, timeDataFile, 2)
 
 print(timeData)
 print(cntData)
 
 basura <- ScatterPlot (cntData, timeData, "TimeData1-5000.pdf")

 timeDataFile<- read.csv(file="/home/CS/c794990g/385DS/HW#3/analysis/TimeData1-8000.csv", header=TRUE)


 cntData <- NULL
 timeData <- NULL
 
 cntData <-PropData(cntData, timeDataFile, 1)
 timeData <- PropData(timeData, timeDataFile, 2)
 
 print(timeData)
 print(cntData)
 
 basura <- ScatterPlot (cntData, timeData, "TimeData1-8000.pdf")
# }

