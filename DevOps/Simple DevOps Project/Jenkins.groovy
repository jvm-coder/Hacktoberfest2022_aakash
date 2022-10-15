 
 node('master'){
    try {
    	def dotnet = '/usr/bin/dotnet'
    	stage('checkout') {
        cleanWs()
    	checkout( /mention checkout path ) 	}
    			stage('Remove obj') {
    		sh 'rm -rf */obj'
    	}
  
    	stage('Build') {
    		sh  'mvn build'
    	}
    	stage('Stop Service') {
    		//stop the service
    	}
    	stage('Publish') {
    		// deploy the java jar file
    	}
		
    	stage('Start Service') {
    		// start the service
		    	}
		
        currentBuild.result = 'SUCCESS'
    } catch (Exception err) {
        currentBuild.result = 'FAILURE'
    }
		   stage('Notify') {
        if(currentBuild.result == 'FAILURE') {
         mail bcc: '', body: "Hi,\n Jenkins have some issues in  ${JOB_NAME} build #${BUILD_NUMBER} \n\n Build URL = ${BUILD_URL} \n\n Job URL = ${JOB_URL}", cc: '', from: 'xxx@gmai.com', replyTo: '', subject: "Problem in ${JOB_NAME} build #${BUILD_NUMBER}", to: 'yyy@gmail.com'
        }
    }
}

