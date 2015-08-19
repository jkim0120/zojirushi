require 'rubygems'
require 'sinatra'
require 'ruby_spark'

enable :sessions

get '/' do
  @core = RubySpark::Core.new('54ff71066678574924590267', '6dfc7bb0441d7fe1712bdf6e664e49bd2ef21a91')
  @light_status = if @core.variable('lightOn') == 0
                    'off'
                  else
                    'on'
                  end

  erb :index
end

post '/lights' do
  @core = RubySpark::Core.new('54ff71066678574924590267', '6dfc7bb0441d7fe1712bdf6e664e49bd2ef21a91')
  @status = params[:status]
  @core.function('toggleLight', @status)

  redirect to('/')
end
