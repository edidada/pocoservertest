#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/JSON/Parser.h>

#include "Poco/JSON/Object.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Query.h"
#include "Poco/JSON/JSONException.h"
#include "Poco/JSON/Stringifier.h"
#include "Poco/JSON/Template.h"
#include "Poco/JSON/PrintHandler.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace Poco::Dynamic;
using namespace Poco::JSON;
using namespace Poco::Net;
using namespace Poco::Util;

class MyRequestHandler : public HTTPRequestHandler
{
public:
	virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
	{
		resp.setStatus(HTTPResponse::HTTP_OK);
		resp.setContentType("text/html");

		ostream & out = resp.send();

		std::string json = "{ \"name\" : \"Franky\", \"children\" : [ \"Jonas\", \"Ellen\" ] }";
		cout<<json<<endl;
		Parser parser;
		Var result = parser.parse(json);
		// ... use result (see next example)
		parser.reset();
		std::ostringstream ostr;
		PrintHandler::Ptr pHandler = new PrintHandler(ostr);
		parser.setHandler(pHandler);
		parser.parse(json);


//	    std::string json = "{ \"test\" : 1969 }";
//	    Poco::JSON::Parser parser;
//	    Poco::DynamicAny result;
//
//	    try
//	    {
//	      DefaultHandler handler;
//	      parser.setHandler(&handler);
//	      parser.parse(json);
//	      result = handler.result();
//	    }
//	    catch(Poco::JSON::JSONException jsone)
//	    {
//	      std::cout << jsone.message() << std::endl;
//	    }
//
//
//	    Poco::JSON::Object::Ptr object = result.extract<Poco::JSON::Object::Ptr>();
//	    Poco::DynamicAny test = object->get("test");
//	    int value = test;


		out << "<h1>Hello World!</h1>";
	}
};

class MyRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
	virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &)
	{
		return new MyRequestHandler;
	}
};

class MyServerApp :public ServerApplication
{
protected:
	int main(const vector<string> &)
	{
		HTTPServer s(new MyRequestHandlerFactory, ServerSocket(8080), new HTTPServerParams);

		s.start();
		cout << endl << "Server started" << endl;

		waitForTerminationRequest();  // wait for CTRL-C or kill

		cout << endl << "Shutting down..." << endl;

		s.stop();

		return Application::EXIT_OK;
	}
};

int main(int argc, char **argv)
{
	MyServerApp app;

	return app.run(argc, argv);
}
