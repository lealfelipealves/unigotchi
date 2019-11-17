import Vue from 'vue';
import axios from 'axios';
import App from './App.vue';
import router from './router';

Vue.prototype.$http = axios;
Vue.prototype.$baseURI = 'http://127.0.0.1:1880';

Vue.config.productionTip = false;

new Vue({
  router,
  render: h => h(App),
}).$mount('#app');
